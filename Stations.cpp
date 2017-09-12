#pragma once
#include "Stations.h"
#include <fstream>
#include <iomanip>
using namespace std;
namespace w2 {
   Stations::Stations(char * fp)
   {
      string temp;
      string ap;
      string sp;
      int counter = 0;

      unsigned size = 0;
      ifstream in(fp);
      if (!in) {
         cout << "Unable to open file";
         exit(1); // terminate with error
      }

      if (in) {
         getline(in, temp, ';');
         size = stoi(temp);
         if (size) {
            numStation = size;
            tableOfStations = new Station[numStation];
         }
         else {
            cout << "Bad Integer, Check File Integrity" << endl;
            exit(2);
         }
      }
      while (in.good() && counter < numStation) {
         getline(in, temp, ';');
         getline(in, sp, ' ');
         getline(in, ap, '\n');
         tableOfStations[counter].set(temp, stoi(sp), stoi(ap));
         counter++;
      }
   }

   void Stations::update() const
   {
      int ap, sp;
      cout << "Passes Sold :" << endl;
      cout << "-------------" << endl;
      for (int i = 0; i < numStation; i++) {
         cout << tableOfStations[i].getName() << endl;
         cout << " Student Passes sold : ";
         cin >> sp;
         tableOfStations[i].update(STUDENT_PASS, -sp);
         cout << " Adult   Passes sold : ";
         cin >> ap;
         tableOfStations[i].update(ADULT_PASS, -ap);
      }

   }

   void Stations::restock() const
   {
      int ap, sp;
      cout << "Passes Added :" << endl;
      cout << "-------------" << endl;
      for (int i = 0; i < numStation; i++) {
         cout << tableOfStations[i].getName() << endl;
         cout << " Student Passes added : ";
         cin >> sp;
         tableOfStations[i].update(STUDENT_PASS, sp);
         cout << " Adult   Passes added : ";
         cin >> ap;
         tableOfStations[i].update(ADULT_PASS, ap);
      }
   }

   void Stations::report() const
   {
      cout << endl << "Passes in Stock : Student Adult" << endl;
      cout << "-------------------------------";
      for (int i = 0; i < numStation; i++) {
         cout << left << setw(19) << tableOfStations[i].getName()  << right 
         << setw(6) <<tableOfStations[i].inStock(STUDENT_PASS) 
         << setw(6) << tableOfStations[i].inStock(ADULT_PASS) << endl;
      }

      //not sure why it is desync-ing by 1 character after the first loop
   }

}
