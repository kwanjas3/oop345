#pragma once
#include<iostream>
#include<string>


using namespace std;

class Grades {
private:
   std::string* studentnum = nullptr;
   double* grade = nullptr;
   size_t s = 0;
public:
   Grades(const char* filename);
   template <typename exp>
   void displayGrades(ostream &os, exp func) const {
      for (size_t i = 0; i < s; i++) {
         os << s << endl;
         os << studentnum[i] << " " << grade[i] << " " << func(grade[i]) << endl;
      }
   }

};