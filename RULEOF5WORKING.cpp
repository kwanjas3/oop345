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
