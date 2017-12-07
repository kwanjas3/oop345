#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
void trimSpace(string& field) {
	size_t p = field.find_first_not_of(" \t");
	field.erase(0, p);
	p = field.find_last_not_of(" \t");
	if (string::npos != p)
		field.erase(p + 1);
}

void csvRead(string filename, char delim) {
	string line;
	string field;
	vector<vector<string>> csvData;
	vector<string> fields;
	fstream fp(filename, ios::in);
	while (getline(fp, line, '\n')) {
		cout << "line: " << line << "<--\n";
		for (size_t i = 0; i < line.size(); i++) {
			if (line[i] != delim) {
				field += line[i];
			}
			else {
//				if (field[0] != 0) {                  // uncomment the 4 lines if you want to skip empty lines
					trimSpace(field);
					fields.push_back(move(field));
//				}
			}
		}
//		if (field[0] != 0) {

		trimSpace(field);
		fields.push_back(move(field));// last field pushback
//		}
		if (!fields.empty())
		csvData.push_back(move(fields));
	}
	/*
	for (auto line = csvData.begin(); line < csvData.end(); line++) {
		for (auto field = line->begin(); field < line->end(); field++)
			cout << *field << " ";
		cout << "\n";
	}
	for (int line = 0; line < csvData.size(); line++) {
		for (int field = 0; field < csvData[line].size(); field++)
			cout << csvData[line][field] << " ";
		cout << "\n";
	}
	*/
	for (auto vec : csvData) {
		for (auto j : vec) {
			cout << '(' << j << ") ";
		}
		cout << '\n';
	}

}

int main(int argc, char** argv) {
	vector<vector<string>> csvData;
	string filename = argv[1];
	char delim = argv[2][0];
	csvRead(filename, delim);



	getchar();
	return 0;
}
