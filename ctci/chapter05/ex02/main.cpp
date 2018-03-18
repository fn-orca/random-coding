#include<bits/stdc++.h>

using namespace std;

string doubleAsBinary(double n) {
	string s = "0.";

	while(n > 0) {
		n *= 2;

		int currentBit = (int) n;
		s += '0' + currentBit;

		if(s.size() > 32) {
			return "ERROR";
		}

		if(currentBit == 1) {
			n -= 1;
		}
	}

	return s;
}

void test0() {
	double n = 0b1 / 2.0;
	string test = doubleAsBinary(n);
	string control = "0.1";

	assert(test == control);
}

void test1() {
	double n = 0b101 / 8.0;
	string test = doubleAsBinary(n);
	string control = "0.101";
	assert(test == control);
}

void test2() {
	double n = ((1LL << 40) - 1) / (double)(1LL<<39);
	string test = doubleAsBinary(n);
	string control = "ERROR";
	assert(test == control);
}

int main() {
	test0();
	test1();
	test2();

	cout << "success" << endl;

	return 0;
}