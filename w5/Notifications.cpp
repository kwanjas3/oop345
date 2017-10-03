#include "Notifications.h"

using namespace std;
namespace w5 {

   Notifications::Notifications()
   {
   }
   Notifications::Notifications(const Notifications &rhs)
   {
      *this = rhs;
   }
   Notifications & Notifications::operator=(const Notifications & rhs)
   {
      if (this != &rhs) {
         count = rhs.count;
         for (size_t i = 0; i < count; i++) {
            msgtab[i] = rhs.msgtab[i];
         }
      }

      return *this;
   }
   Notifications::Notifications(Notifications && rhs)
   {
      *this = move(rhs);
   }
   Notifications && Notifications::operator=(Notifications && rhs)
   {
      if (this != &rhs) {
         count = rhs.count;
         for (size_t i = 0; i < count; i++) {
            msgtab[i] = rhs.msgtab[i];
         }
         rhs.count = 0;
      }

      return move(*this);
   }
   Notifications::~Notifications()
   {
   }
   void Notifications::operator+=(const Message & msg)
   {
      if (count < maxSize) {
         msgtab[count] = msg;
         count++;
      }
      else {
         cerr << "Max size reached" << endl;
      }
   }
   void Notifications::display(std::ostream & os)
   {
      for (size_t i = 0; i < count; i++) {
         msgtab[i].display(os);
      }
   }
}
