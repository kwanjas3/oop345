#include <iostream>

using namespace std;

template<class T>
bool testBit(T target, int bit) {
	T mask = (T(1) << bit);
	return target & mask;
}

template<class T>
void printBits(T target) {
	for (int bit = 8 * sizeof(target) - 1; bit >= 0; bit--)
		cout <<"01"[testBit(target, bit)]; // 01 or use tf since testbit returns true or false first postition is FALSE THEN TRUE
}

int main(int argc, char** argv) {
	unsigned short A = 0, B = 0;
	if (argc > 1) 
		A = atoi(argv[1]);
	
	if (argc > 1)
		B = atoi(argv[2]);

	cout << "A= "; printBits(A); cout << '-'<<A << '\n'; // arguments are 1 2 this program shows the bit equivalent of the integer
	cout << "B= "; printBits(B); cout << '-'<<B << '\n';
	//auto op = A&B; promotes to 32 bits;
	decltype(A) op = A&B; //declares type as A for var OP
	cout << "A&B= "; printBits(op); cout << '-' << op << '\n'; // & bit operator compares to bits returns 1 at locations where both at 1
	// | <- or operator for bits
	decltype(A) op1 = A | B;
	cout << "A|B= "; printBits(op1); cout << '-' << op1 << '\n';

	//exclusive OR XOR
	decltype(A) op2 = A^B;
	cout << "A^B= "; printBits(op2); cout << '-' << op2 << '\n';

	

}
