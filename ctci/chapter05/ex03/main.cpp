#include<bits/stdc++.h>

using namespace std;

int maxOnesBlock(int n) {
	int ans = 1;

	int lastBit = 0;
	int ones1 = 0;
	int ones2 = 0;
	int zeroes = 0;
	int count = 31;

	while(count--) {
		int bit = n & 1;

		if(bit == 1) {
			if(zeroes == 0) {
				ones1++;
			}
			if(zeroes == 1) {
				ones2++;
			}

			int current = ones1 + 1 + ones2;

			ans = max(ans, current);
		} 
		if(bit == 0) {
			if(lastBit == 0) {
				ones1 = 0;
				ones2 = 0;
				zeroes = 0;
			}
			if(lastBit == 1) {
				zeroes++;
				
				if(zeroes > 1) {
					zeroes = 1;
					ones1 = ones2;
					ones2 = 0;
				}
			}
		}

		lastBit = bit;
		n >>= 1;
	}

	return min(ans, 31);
}

void test0() {
	int n = 0b11011;
	int test = maxOnesBlock(n);
	int control = 5;

	assert(test == control);
}

void test1() {
	int n = 0b110011;
	int test = maxOnesBlock(n);
	int control = 3;

	assert(test == control);
}

void test2() {
	int n = 0b0;
	int test = maxOnesBlock(n);
	int control = 1;

	assert(test == control);
}

void test3() {
	int n = 0b1;
	int test = maxOnesBlock(n);
	int control = 2;

	assert(test == control);
}

void test4() {
	int n = ~0;
	int test = maxOnesBlock(n);
	int control = 31;

	assert(test == control);
}

void test5() {
	int n = 0b1001011001;
	int test = maxOnesBlock(n);
	int control = 4;

	assert(test == control);
}

void test6() {
	int n = 1775;
	int test = maxOnesBlock(n);
	int control = 8;

	assert(test == control);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	cout << "success" << endl;

	return 0;
}