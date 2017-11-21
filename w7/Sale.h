#pragma once
#include <iostream>
#include <vector>
#include "iProduct.h"
using namespace std;

namespace w7 {
	class Sale
	{
	private:
		vector<iProduct*> pl;
	public:
		Sale(const char*);
		void display(std::ostream& os) const;  //receives a reference to the output object and displays the sale information as shown in the sample output above.The output includes column headings and the total sale amount including taxes paid.The product number and cost occupy fields of width 10.
	};
}

