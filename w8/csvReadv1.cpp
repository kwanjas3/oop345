#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void trimSpace(string& s) {
	while (s.empty() && s[0] == ' ') {
		s.erase(0, 1);
	}
}

void csvRead(string filename, char sep) {
	vector<vector<string>> csvData;
	fstream in(filename, ios::in);
	if (!in.is_open()) {
		throw string("cannot open file ") + filename;
	}
	string line;
	auto cr = line.find('\r');
	//delete \r
	if (cr != string::npos) {
		line.erase(cr);
	}

	while (getline(in, line)) {
		cout << "line -> " << line << "<-\n";

		//vector of fields
		vector<string> fields;
		string field;
		for (size_t index = 0; index < line.size(); index++) {
			if (line[index] != sep) {
				field += line[index];
			}else{//seperator
				//fields.push_back(field);
				//field.clear();
				fields.push_back(move(field));
				for (auto &e : fields) {
					cout << '-' << e << '-';
				}
				cout << endl;
			}
			trimSpace(field);
			fields.push_back(move(field));
		}
		csvData.push_back(move(fields));
	}

	in.close();
}


int main(int argc, char* argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << "csv-file csv-seperator\n";
		exit(1);
	}
	try {
		vector<vector<string>> csvData;
		string filename = argv[1]; // arg 1
		char sep = argv[2][0]; // first character of 2nd argument
		csvRead(filename, sep);
	return 0;
	}
	catch (const string& err) {
		cerr << "It threw: " << err << endl;
		return 1;
	}
}
