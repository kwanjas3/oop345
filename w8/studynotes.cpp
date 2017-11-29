#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class X {
private:
	T *p = nullptr;
	size_t s = 0;
public:
	X() {}
	~X() { delete[]p; }
	X(const X& rhs) {
		*this = rhs;
		cout << "copy constr \n";
	}
	X(const T val, size_t size) {
		s = size;
		p = new T[size];
		for (size_t i = 0; i < size; i++) {
			p[i] = val;
		}
	}
	X& operator=(const X& rhs) {
		if (this != &rhs) {
			delete[]p;
			s = rhs.s;
			if (rhs.p) {
				p = new T[s];
				memcpy(p, rhs.p, sizeof(T)*s);
			}
			else {
				p = nullptr;
			}
		}
		cout << "copy assign \n";
		return *this;
	}

	X(X&& rhs) {
		cout << "copy move";
		*this = move(rhs);
	}

	X&& operator=(X&& rhs) {
		if (this != &rhs) {
			delete[]p;
			s = rhs.s;
			p = rhs.p;
			rhs.p = nullptr;
			rhs.s = 0;
		}
		else {
			p = nullptr;

		}
		cout << "move assignment \n";
		return move(*this);
	}
	void display() {
		for (size_t i = 0; i < s; i++) {
			cout << p[i] << endl;
		}
	}
};
void printVector(vector<int> vec) {
	for (auto x : vec) {
		cout << x << endl;
	}
}
int goo(int x) {
	return x;
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << '\n';
	}

	X<double> x1;
	X<double> x2(100, 3);
	x2.display();
	X<double> x3 = x2;
	x3.display();
	x1 = move(x3);
	x1.display();

	//vectors

	vector<int> testing;
	testing.assign(5, 25);
	testing.push_back(26);
	

	auto it = testing.begin();
	it = testing.insert(it, 2); // iterator at the beginning, adds a 2 opposite of push_back
	printVector(testing);
	cout << "---------------------------------------------\n";
	testing.insert(it, 3, 300);
	printVector(testing);
	cout << testing.capacity() << endl;

	//function pointers

	auto foo = [] {cout << "testing123" << endl; };
	foo();
	////function pointer
	void (*ts)() = foo; // void is return type, (*NAME of function pointer dont forget the star), (arg)
	ts(); // calls foo

	auto goo = [] (auto x) {return x; };
	int(*fp)(int) = goo;
	cout << goo(4) << endl;
}
