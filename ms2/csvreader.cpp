#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "util.h"


using namespace std;
void trimSpace(string& field) {
	size_t p = field.find_first_not_of(" \t");
	field.erase(0, p);
	p = field.find_last_not_of(" \t");
	if (string::npos != p)
		field.erase(p + 1);
}

void csvprint(vector<vector<string>> csvData) {
	for (auto vec : csvData) {
		cout << "name/slots/pass/fail: ";
		for (auto j : vec) {
			cout << j << "/";
		}
		cout << '\n';
	}
}

void csvRead(string filename, char delim, std::vector< std::vector<std::string> > &csv) {
	string line;
	string field;
	vector<string> fields;
	fstream fp(filename, ios::in);
	while (getline(fp, line, '\n')) {
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
		csv.push_back(move(fields));
	}
}