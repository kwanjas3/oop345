#include "Grades.h"
#include <fstream>
using namespace std;
Grades::Grades(const char * filename)
{
   std::string line;
   ifstream fp;
   fp.open(filename);
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

}

Grades::~Grades(){
 delete[] grade;
}
