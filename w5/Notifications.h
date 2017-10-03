#pragma once
#include "Message.h"
using namespace std;
namespace w5 {
   const size_t maxSize = 10;
   class Notifications {
      Message msgtab[maxSize];
      size_t count = 0;
   public:
      Notifications();// -default constructor - empty
      Notifications(const Notifications&);// -copy constructor
      Notifications& operator=(const Notifications&);// -copy assignment operator
      Notifications(Notifications&&);// -move constructor
      Notifications&& operator=(Notifications&&);// -move assignment operator
      ~Notifications();// -destructor
      void operator+=(const Message& msg);// -adds msg to the set
      void display(std::ostream& os);// const - inserts the Message objects to the os output stream
   };

}