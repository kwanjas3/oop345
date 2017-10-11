#include "Grades.h"
#include <fstream>
using namespace std;
Grades::Grades(const char * filename)
{
   try {
   std::string line;
   ifstream fp;
   fp.open(filename);
   if (!fp) throw exception("could not open file: ");
   //get size of file

   if (fp.is_open()) {
      while (getline(fp, line, '\n')) {
      s++;
      }
   }
   //clear eof error
   fp.clear();
   fp.seekg(0); // rewind

   studentnum = new string[s];
   grade = new double[s];

   for (size_t i = 0; i < s; i++) {
      getline(fp, studentnum[i], ' ');
      getline(fp, line);
      grade[i] = stod(line);
      cout << i << endl;
   }
   fp.close();
   } catch(const exception& err){ cerr << err.what() << " " << filename << endl; }
}

Grades::~Grades(){
 delete[] grade;
}
