#include<bits/stdc++.h>

using namespace std;

int multiply(int a, int b) {
	int mini = a < b ? a : b;
	int maxi = a < b ? b : a;

	if(mini == 0) {
		return 0;
	}

	int sumOdds = 0;

	while(mini > 1) {
		if(mini & 1 == 0) {
			maxi <<= 1;
			mini >>= 1;
		} else {
			sumOdds += maxi;
			mini--;
		}
	}

	return maxi + sumOdds;
}

void test0() {
	int a = 2;
	int b = 5;

	int test = multiply(a, b);
	int control = a*b;

	assert(test == control);
}

void test1() {
	int a = 6;
	int b = 8;

	int test = multiply(a, b);
	int control = a*b;

	assert(test == control);
}

void test2() {
	int a = 7;
	int b = 8;

	int test = multiply(a, b);
	int control = a*b;

	assert(test == control);
}

void test3() {
	int a = 111;
	int b = 35469;

	int test = multiply(a, b);
	int control = a*b;

	assert(test == control);
}

int main() {
	test0();
	test1();
	test2();
	test3();

	cout << "success" << endl;

	return 0;
}

/*

7*8 = 56
6*8 + 8 = 56
3*8*2 + 8 = 56
2*8*2 + 8 + 8*2 = 56 

*/