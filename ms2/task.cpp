#include "util.h"
using namespace std;

class Task {
	string name, slots{ "1" }, pass, fail;
public:
	Task() {}
	Task(vector<string>& line) { // parsing fields
		switch (line.size()) {
		case 4:
			if (validateTask(line[3]))
				fail = line[3];
			else throw string("bad fail");
		case 3:
			if (validateTask(line[2]))
				pass = line[2];
			else throw string("bad pass");
		case 2:
			if (validSlots(line[1]))
				slots = line[1];
			else throw string("bad slots");
		case 1:
			if (validateTask(line[0]))
				name = line[0];
			else throw string("bad task");
			break;
		default:
			throw string("bad line found ") + to_string(line.size()) + " field , expected 1,2,3, or 4\n";
		}
	}


	void graph(fstream& dotfile) {
		if (pass.empty() && fail.empty()) {
			dotfile << '"' << name << '"' << ";\n";
		}
		if (!pass.empty()) {
			dotfile << '"' << name << '"'
				<< " -> "
				<< '"' << pass << '"'
				<< " [color=green];\n";
		}
		if (!fail.empty()) {
			dotfile << '"' << name << '"'
				<< " -> "
				<< '"' << fail << '"'
				<< " [color=red];\n";
		}
	}
	void print() {
		cout << "name/slots/pass/fail = " << name
			<< '/' << slots
			<< '/' << pass
			<< '/' << fail << '\n';
	}
};

class TaskManager {
	vector<Task> taskList;
public:
	TaskManager(vector<vector<string>> & csvTaskData) {
		for (auto &line : csvTaskData) {
			try {
				taskList.push_back(Task(line));
			}
			catch (const string& e) {
				cerr << "problem: " << e << endl;
			}
		}
	}
	void print() {
		for (auto& t : taskList) {
			t.print();
		}
	}
	void graph(string& filename) {
		string dotFilename = filename + ".gv";
		fstream dotFile(dotFilename, ios::out | ios::trunc); // write new if already exists
		if (dotFile.is_open()) {
			dotFile << "digraph taskgraph {\n";
			for (auto &t : taskList) {
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
	TaskManager tm(csvData);
	tm.print();
	tm.graph(filename);

	getchar();
	return 0;
}