#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
namespace w2 {
   enum PassType { ADULT_PASS, STUDENT_PASS, PASS_COUNT };
   class Station {
   private:
      string name;
      unsigned sp;
      unsigned ap;

   public:
      Station();                                      // -a default constructor that initializes the instance variables through an initialization list
      void set(const std::string& nm, unsigned s, unsigned a);// -sets the instance variables to the values received in its parameters
      void update(PassType t, int x);                     // -updates the number of passes - sold if negative, added if positive
      unsigned inStock(PassType) const;               // -returns the number of passes of the requested type
      const std::string& getName() const;             // -returns a reference to a string object holding the name of the station
   };


}