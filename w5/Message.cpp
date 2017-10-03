#include "Message.h"
#include <fstream>

using namespace std;
namespace w5 {

   Message::Message(std::ifstream & in, char c)
   {
      string line;
      getline(in, line);
      size_t i = 0;
      while (i < line.size() && line[i] != ' ') {
         name += line[i];
         i++;
      }
      i++;//skip space
      if (i< line.size() && line[i] == '@') {
         i++;
         while (i < line.size() && line[i] != ' ') {
            reply += line[i];
            i++;
         }
         i++;//skip space
      }

      while (i < line.size() && line[i] != c) {
         tweet += line[i];
         i++;
      }
      if (tweet.empty()) {
         name.clear();
         reply.clear();
      }
   }
   bool Message::empty() const
   {
      return tweet.empty() || name.empty();
   }
   void Message::display(std::ostream & os) const
   {
      if (!tweet.empty()) {
         os << "Message" << endl;
         os << "User : " << name << endl;
         if (!reply.empty()) {
            os << "Reply : " << reply << endl;
         }
         os << "Tweet : " << tweet << endl << endl;
      }
   }
}