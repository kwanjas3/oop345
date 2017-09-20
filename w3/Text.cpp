#include "Text.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace w3 {
   Text::Text() : b(nullptr), s(0)
   {
      b = nullptr;
      s = 0;
   }
   Text::Text(const char * filename) : b(nullptr), s(0)
   {
      string temp;
      fstream fp(filename, ios::in);
      if (!fp.is_open()) {
         cout << "Cannot open file\n";
      }
      else {
         while (getline(fp, temp)) { s++; }         //count and go through once to initialize size
         fp.clear();
         fp.seekp(0);
         cout << "Finished Reading File... Allocating..." << endl;
         b = new string[s]; //allocate mem
         for (size_t i = 0; i < s; i++) {
            getline(fp, b[i]);// read into array
         }
         cout << "finished loading into array" << endl;
      }
      fp.close();
   }
   Text::~Text()
   {
      delete[] b;
   }
   Text::Text(const Text & rhs)
   {
      b = nullptr;
      *this = rhs;
   }
   Text & Text::operator=(const Text & rhs)
   {
      cout << "Currently in Assignment Operator\n";
      if (this != &rhs) {
         delete[] b;

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
         cout << "self assignment occured\n";
      }
      return *this;
   }
   Text::Text(Text && rhs)
   {
      b = nullptr;
      *this = move(rhs);
   }
   Text && Text::operator=(Text && rhs)
   {
      cout << "Currently in Move Assignment Operator\n";
      if (this != &rhs) {
         delete[] b;
         s = rhs.s;
         b = rhs.b;
         rhs.b = nullptr;
         rhs.s = 0;
      }
      else {
         cout << "Self Move Assignment occurred\n";
      }
      return move(*this);
   }
   size_t Text::size() const
   {
      return s;
   }
}

