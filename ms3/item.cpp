#include "util.h"
using namespace std;

class item {
	string name, installer, remover, sequenceNumber, description;
public:
	item() {}
	item(vector<string>& line) { // parsing fields
		switch (line.size()) {
		case 5:
				description= line[4];
		case 4:
			if (validSequenceNumber(line[3]))
				sequenceNumber = line[3];
			else throw string("bad sequence number");
			if (validateItem(line[2]))
				remover = line[2];
			else throw string("bad remover task");
			if (validateItem(line[1]))
				installer = line[1];
			else throw string("bad installer task");
			if (validateItem(line[0]))
				name = line[0];
			break;
		default:
			throw string("bad line found ") + to_string(line.size()) + " field , expected 1,2,3, or 4\n";
		}
	}


	void graph(fstream& dotfile) {
			dotfile << '"' << name << '"'
				<< " -> "
				<< '"' <<"installer: " <<installer << '"'
				<< " [color=green];\n";

			dotfile << '"' << name << '"'
				<< " -> "
				<< '"' <<"remover: "<< remover << '"'
				<< " [color=red];\n";
		
	}
	void print() {
		cout << "name/installer/remover/sequenceNumber/description = " << name
			<< '/' << installer
			<< '/' << remover
			<< '/' << sequenceNumber 
			<< '/' << description
			<< '\n';
	}
};

class itemManager {
	vector<item> itemList;
public:
	itemManager(vector<vector<string>> & csvitemData) {
		for (auto &line : csvitemData) {
			try {
				itemList.push_back(item(line));
			}
			catch (const string& e) {
				cerr << "problem: " << e << endl;
			}
		}
	}
	void print() {
		for (auto& t : itemList) {
			t.print();
		}
	}
	void graph(string& filename) {
		string dotFilename = filename + ".gv";
		fstream dotFile(dotFilename, ios::out | ios::trunc); // write new if already exists
		if (dotFile.is_open()) {
			dotFile << "digraph itemgraph {\n";
			for (auto &t : itemList) {
				t.graph(dotFile);
			}
			dotFile << "}\n";
			dotFile.close();
		}
	}
};
/*
int main(int argc, char** argv) {
	vector<vector<string>> csvData;
	string filename = argv[1];
	char delim = argv[2][0];
	csvRead(filename, delim, csvData);
	csvprint(csvData);
	itemManager tm(csvData);
	tm.print();
	tm.graph(filename);

	getchar();
	return 0;
}
*/