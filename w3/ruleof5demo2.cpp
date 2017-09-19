#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace w3 {
	class Text {
		string * b = nullptr;
		size_t s = 0;
	public:
		Text();
		Text(char * fp) {
			//ifstream f(fp);
			std::fstream f(fp, ios::in);
			if (!f.is_open()) {
				cout << "cannot open \n";
				exit(1);
			}
			string line;
			//count lines
			while (getline(f, line)) 
				s++;
			cout << "done reading \n";
			b = new string[s];
			f.clear();//reset error state @ eof, 
			// rewind file
			f.seekp(0);
			for (size_t i = 0; i < s; i++) {
				getline(f, b[i]);
			}

			f.close();

		}
		~Text() {
			delete[]b;
		}

		Text& operator = (const Text& rhs) {
			if (this != &rhs) {
				delete[] b;
				b = nullptr;
				s = 0;
				if (rhs.b) {
					s = rhs.s;
					b = new string[s];
					for (size_t i = 0; i < s; i++) {
						b[i] = rhs.b[i];
					}
				}
			}
			else {

			}
		}
		Text(const Text& rhs) {
			*this = rhs;
		}
		Text&& operator = (Text&& rhs) {
			if (this != &rhs) {
				delete[]b; //delete our brains
				b = rhs.b; // steal brains
				s = rhs.s; //steal size
				rhs.b = nullptr; //zombie ggnore
				rhs.s = 0;
			}
			else {

			}
		}

		Text(Text&& rhs) {
			*this = move(rhs);
		}
		size_t size() const {
			return s;
		}
	};
}

///////////////////
