/*
question 1 rule of 5, 
question 2 walkthrough - 
start at main, clone function abstract base class,
lambda's - auto p = [] {cout << x << endl;}
auto f = [] {cout << whatever << endl}
nameless
[]{cout << kappa;}

1. variable, static = local and private to that file 
2. class variable static = B::count 
			static int count = 0;
			
3. Vectors, pop(deletes), push.back (addbehind), back(last entry), insert
v<double>X
X.being()
X.end();

function pointers
https://www.cprogramming.com/tutorial/function-pointers.html
prints it out 5 times the same.

*/
#include <iostream>
using namespace std;
template<typename T>
class X {
private:
	T* p = nullptr;
	size_t s = 0;
	
public:
	//X(){}
	//X(){p = nullptr; s = 0}
	X() : p(nullptr), s(0) { cout << "default" << endl; }
	~X(){delete [] p;}
	X(const T value, size_t size) {
		s = size;
		p = new T[size];
		for (size_t i = 0; i < s; i++) {
			p[i] = value;
		}
		cout << "2arg default" << endl;
	}

	X(const X& rhs) : p(nullptr), s(0) {
		*this = rhs;
		cout << "CC constructor" << endl;
	}

	X& operator=(const X& rhs) {
		if (this != &rhs) {
			s = rhs.s;
			delete[] p;
			if (rhs.p) {
				p = rhs.p;
				p = new T[s];
				memcpy(p, rhs.p, s*sizeof(T));
			}
			else {
				p = nullptr;
			}
		}
		cout << "assignment operator" << endl;
		return *this;
	}

	X(X&& rhs) : p(nullptr), s(0){
		*this = move(rhs);
		cout << "move constructor" << endl;
	}

	X&& operator= (X&& rhs) {
		if (this != &rhs) {
			s = rhs.s;
			delete[]p;
			if (rhs.p) {
				p = rhs.p;
				rhs.p = nullptr;
				rhs.s = 0;
			}
			else {
				p = nullptr;
			}
		}
		cout << "move assignment operator" << endl;
		return move(*this);
	}
};

int main(int argv, char* argc[]) {
	X<double> x1;
	X<double> x2(10, 5);
	x1 = x2;
	x1 = move(x2);
	X<double> X3(move(x1));
	
}
