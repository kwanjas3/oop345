#include "util.h"
using namespace std;

class Order {
	string customer, product;
	vector<string> itemList;
public:
	Order() {}
	Order(vector<string>& line) { // parsing fields
		if (line.size() < 3) {
			throw string("bad line found ") + to_string(line.size()) + " field , expected 3 or more\n";
		}
		else {
			if (validCustomerName(line[0]))
				customer = line[0];
			else
				throw string("bad name found ");

			if (validProductName(line[1]))
				product = line[1];
			else
				throw string("bad product found ");

			for (size_t i = 2; i < line.size(); i++) {
				if (line[i].empty())
					continue; // skips the empty pushback

				if (validateItem(line[i]))
					itemList.push_back(move(line[i]));
				else
					throw string("bad item name");
			}

		}

	}


	void graph(fstream& dotfile) {
		for (auto& e:itemList)
		dotfile << '"' << customer << "\n" << product << '"' 
			<< " -> "
			<< '"' << "item: " << e << '"'
			<< " [color=blue];\n";



	}
	void print() {
		cout << "cname/product/itemList/ = " << customer
			<< '/' << product;

		for (auto &e : itemList) {
			cout << '/' << e;
		}

		cout<< '\n';
	}
};

class OrderManager {
	vector<Order> OrderList;
public:
	OrderManager(vector<vector<string>> & csvOrderData) {
		for (auto &line : csvOrderData) {
			try {
				OrderList.push_back(Order(line));
			}
			catch (const string& e) {
				cerr << "problem: " << e << endl;
			}
		}
	}
	void print() {
		for (auto& t : OrderList) {
			t.print();
		}
	}
	void graph(string& filename) {
		string dotFilename = filename + ".gv";
		fstream dotFile(dotFilename, ios::out | ios::trunc); // write new if already exists
		if (dotFile.is_open()) {
			dotFile << "digraph Ordergraph {\n";
			for (auto &t : OrderList) {
				t.graph(dotFile);
			}
			dotFile << "}\n";
			dotFile.close();
		}
	}
};

int main(int argc, char** argv) {
	vector<vector<string>> csvData;
	string filename = argv[1];
	char delim = argv[2][0];
	csvRead(filename, delim, csvData);
	csvprint(csvData);
	OrderManager tm(csvData);
	tm.print();
	tm.graph(filename);

	getchar();
	return 0;
}