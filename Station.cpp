#include "Station.h"

w2::Station::Station()
{
   name = "";
   sp = 0;
   ap = 0;
}

void w2::Station::set(const std::string & nm, unsigned s, unsigned a)
{
   name = nm;
   sp = s;
   ap = a;
}

void w2::Station::update(PassType t, int x)
{
   if (t == 0) {
      ap += x;
   }
   if (t == 1) {
      sp += x;
   }
}

unsigned w2::Station::inStock(PassType x) const
{
   return (x?sp:ap);
}

const std::string & w2::Station::getName() const
{
   return name;
}
