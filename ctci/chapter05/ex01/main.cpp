#include<bits/stdc++.h>

using namespace std;

int insertMIntoN(int n, int m, int i, int j) {
	int iToJOnes = (1 << (j-i+1)) - 1;
	int shiftedOnes = iToJOnes << i;
	int reversedShiftedOnes = ~shiftedOnes;

	// set n[i:j] to 0
	n &= reversedShiftedOnes;

	// allign m to i
	m <<= i;

	return n |= m;
}

void test0() {
	int n = 0b10000000000;
	int m = 0b10011;
	int i = 2;
	int j = 6;

	int control = 0b10001001100;

	int test = insertMIntoN(n, m, i, j);

	assert(test == control);
}

void test1() {
	int n = 0b101;
	int m = 0b1;
	int i = 1;
	int j = 1;

	int control = 0b111;
	int test = insertMIntoN(n, m, i, j);

	assert(test == control);
}

int main() {
	test0();
	test1();

	cout << "success" << endl;

	return 0;
}