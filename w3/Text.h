#pragma once
#include <string>

using namespace std;

namespace w3 {
   class Text {
   private:
      string* b;
      size_t s;
   public:
      Text();
      Text(const char * filename); // file 
      ~Text();
      Text(const Text& rhs); // copy constructor
      Text & operator= (const Text& rhs); // assignment operator
      Text(Text&& rhs);
      Text&& operator= (Text&& rhs);
      size_t size() const;
   };



}