#include<bits/stdc++.h>

using namespace std;

int getConversionCount(int a, int b) {
	int count = 0;

	for(int c = a^b; c; c &= (c - 1)) {
		count++;
	}

	return count;
}

void test0() {
	int a = 0b0;
	int b = 0b1;

	int test = getConversionCount(a, b);
	int control = 1;

	assert(test == control);
}

void test1() {
	int a = 0b101;
	int b = 0b010;

	int test = getConversionCount(a, b);
	int control = 3;

	assert(test == control);
}

void test2() {
	int a = 0b011;
	int b = 0b001;

	int test = getConversionCount(a, b);
	int control = 1;

	assert(test == control);
}

void test3() {
	int a = 0b011;
	int b = 0b011;

	int test = getConversionCount(a, b);
	int control = 0;

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