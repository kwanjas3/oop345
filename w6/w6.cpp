// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
   if (argc != 2) {
      std::cerr << argv[0] <<
         ": incorrect number of arguments\n";
      std::cerr << "Usage: " << argv[0] << " file_name\n";
      return 1;
   }


   Grades grades(argv[1]);
   // define the lambda expression for letter
   auto letter =[](double grade)->std::string {
      std::string tmp;
      if (grade >= 90)
         tmp = "A+";
      else if (grade>80)
         tmp = "A";
      else if (grade>75)
         tmp ="B+";
      else if (grade>70)
         tmp ="B";
      else if (grade>65)
         tmp = "C+";
      else if (grade>60)
         tmp = "C";
      else if (grade>55)
         tmp = "D+";
      else if (grade>50)
         tmp = "D";
      else
         tmp = "F";
      return tmp;
   };
   grades.displayGrades(std::cout, letter);

   std::cout << "Press any key to continue ... ";
   std::cin.get();
}