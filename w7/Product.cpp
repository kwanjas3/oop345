#include <iostream>
#include "iProduct.h"
#include <iomanip>
namespace w7 {
	Product::Product(const int i, const double p) {
		id = i;
		cost = p;
	}

	double Product::getCharge() const
	{
		return cost;
	}

	void Product::display(ostream & os) const
	{
		os << std::setw(10) << std::right;
		os << id;
		os << std::setw(10) << std::right;
		os << cost << '\n';
	}
	/////Taxed Products
	TProduct::TProduct(const int i, const double p, const char t) {
		id = i;
		cost = p;
		taxed = t;
	}
	double TProduct::getCharge() const
	{
		double rate = 1;
		if (taxed == 'H') 
			rate = 1.13;
		if (taxed == 'P') 
			rate = 1.08;
		return cost*rate;
	}
	void TProduct::display(ostream & os) const
	{
		os << std::setw(10) << std::right << id << std::setw(10) << std::right << cost;
		os << ' ';
		if (taxed == 'H') os << "HST";
		if (taxed == 'P') os << "PST";
		os << '\n';
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
		prod.display(os);
		return os;
	}
	iProduct* readProduct(ifstream &fs) {
		int idr;
		double pr;
		char taxedr;
		iProduct* temp;

		fs >> idr >> pr;
		if (fs.get() != '\n') {
			fs.get(taxedr);
			temp = new TProduct(idr, pr, taxedr);
		}
		else temp = new Product(idr, pr);
		return temp;
	}
}