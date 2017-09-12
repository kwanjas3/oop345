#pragma once
#include "Station.h"

namespace w2 {
   class Stations {
   private:
      unsigned numStation = 0;
      Station * tableOfStations = nullptr;
   public:
      Stations(char * fp);
      void update() const;// -accepts the number of passes sold and updates the data for each station in turn
      void restock() const;// -accepts the number of passes added and updates the data for each station in turn
      void report() const;// -reports the number of passes currently available at each station

   };


}