// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "SecureData.h"

using namespace std;

namespace w10 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {

        const unsigned int nthreads = 4;
        const unsigned int chunkSize = nbytes / nthreads;
        thread threads[nthreads];
        Cryptor cryptors[nthreads];
        
        for (int j = 0; j<nthreads; ++j) {
            threads[j] = std::thread(std::bind(
                converter,
                text + j * chunkSize,
                key,
                j + 1 < nthreads ? chunkSize : (nbytes - j*chunkSize),
                cryptors[j]
            ));
        }

        for (int j = 0; j<nthreads; ++j) threads[j].join();
        encoded = !encoded;

        
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary
            fstream os(file, ios::out);
            if (!os) throw string("failed to open file: ") + file;
			// write binary file here
            for (int i = 0; i < nbytes; i++)
                os << text[i];
		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
        fstream istr(file, ios::in);
        if (!istr) throw string("failed to open file: ") + file;

		// allocate memory here
        nbytes = -1;
        istr >> noskipws;
        char temp;
        while (istr.good()) {
            istr >> temp;
            nbytes++;
        }
        text = new char[nbytes + 1];
		// read binary file here
        istr.clear();
        istr.seekg(0, ios::beg);
        nbytes = -1;
        while (istr.good()) 
            istr >> text[++nbytes];
        


		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}