#include "Sale.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "iProduct.h"

using namespace std;
namespace w7 {
	Sale::Sale(const char* fn) {
		std::ifstream file(fn);
		while (file.good()) {
			iProduct* ip = readProduct(file);
			pl.push_back(ip);
		}
		pl.pop_back();
	}

	void Sale::display(std::ostream& os) const {
		double sum = 0;
		os << "Product No      Cost Taxable\n";
		os << std::fixed << std::setprecision(2);

		for (auto p : pl) {
			os << *p;
			sum += p->getCharge();
		}
		os << "  Total" << std::setw(10) << std::right << sum << '\n';
	}
}
