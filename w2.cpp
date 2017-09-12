#include <iostream>
#include "Stations.h"

using namespace std;

//FILE* fp = freopen("inputs.txt", "r", stdin); 
// uncomment the line above so you do not have to 
// type in the values I include an input file for the cin values
//output will look weird because the input values are not echoed on console.

int main(int argc, char* argv[]) {
   std::cout << "\nCommand Line : ";
   for (int i = 0; i < argc; i++) {
      std::cout << argv[i] << ' ';
   }
   std::cout << std::endl;
   if (argc != 2) {
      std::cerr << "\nIncorrect number of arguments\n";
      return 1;
   }
   w2::Stations stations(argv[1]);
   stations.update();
   stations.restock();
   stations.report();
   return 0;
}