#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>

using namespace std;
namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

	class Product : public iProduct {
	private:
		int id;
		double cost;
	public:
		Product(const int i, const double p);
		double getCharge()const;
		void display(ostream&) const;
	};

	class TProduct : public iProduct {
	private:
		int id;
		double cost;
		char taxed;
	public:
		TProduct(const int i, const double p, const char t);
		double getCharge()const;
		void display(ostream&) const;

	};

}
#endif