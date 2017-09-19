#include <iostream>
using namespace std;
//rule of 5
template <typename T>
class X {
	T* b;
	size_t size;
public:
	X() : b(nullptr), size(0) {
		//b = nullptr;
		//size = 0;
	}
	X(size_t s) : size(s), b(new T[size]) // size_t automatic int generates as 64 or 32bit
	{
		cout << "X(" << s << ")\n";
		cout << "X(" << size << ")\n";
	}

	~X() {
		delete[] b;
		cout << "X(" << size << ")\n";
	}

	//assignment operator

	X& operator=(const X& rhs) {
		cout << "operator = (" << rhs.size << ")\n";
		if (this != &rhs) {
			cout << "Kappa got Zombied" << endl;
			delete[] b;
			size = 0;
			b = nullptr;
			if (rhs.b) {
				size = rhs.size; // size of brains
				b = new T[size]; // new mem
				memcpy(b, rhs.b, size * sizeof(T)); // deep copy of brains size multiply by size of whatever int 4bytes or 8 bytes
			}
		}
		else {
			cout << "Copy Assignment operator self assignment" << endl;
		}
		return *this;
	}

	//copy constructor
	X(const X& rhs) {
		cout << "operator = (" << rhs.size << ")\n";
		*this = rhs;
	}
//rule of 5 
	X&& operator=(X&& rhs) { //move assignment operator rhs is actually lhs in this move constructor
		cout << "operator = (" << rhs.size << ")\n";
		if (this != &rhs) {
			cout << "Kappa got Zombied" << endl;
			delete[] b;
			size = rhs.size;
			b = rhs.b;
			rhs.size = 0;
			rhs.b = nullptr;
		}
		else {
			cout << "Copy Assignment operator self assignment" << endl;
		}
		return std::move(*this);
	}

	//copy constructor
	X( X&& rhs) {
		cout << "move operator = (" << rhs.size << ")\n";
		*this = std::move(rhs);
	}

	void print() {
		cout << "size=" << size << ", " << size * sizeof(T) << " bytes\n";
	}
};


int main() {
	X<double> x1, x2(1000000);
	cout << "x1 :"; x1.print();
	x1 = x2; //assignment operator test
	X<double> x3(x2); //Copy constructor
	X<double> x4 = x3; // copy ctor

	x1 = std::move(x4); // steal from x4 give to x1
	x4 = move(x1);

	X<double> x5(move(x4));
	X<double> x6(move(x5));
}
