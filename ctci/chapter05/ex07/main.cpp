#include<bits/stdc++.h>

using namespace std;

const unsigned int aux = 0b10101010101010101010101010101010;

unsigned int pairwiseSwap(unsigned int a) {
	int x = a << 1;
	x &= aux;
	int y = a >> 1;
	y &= (aux >> 1);

	return x | y;
}

void test0() {
	int a = 0b010;

	int test = pairwiseSwap(a);
	int control = 0b001;

	assert(test == control);
}

void test1() {
	int a = 0b1010;

	int test = pairwiseSwap(a);
	int control = 0b0101;

	assert(test == control);
}

int main() {
	test0();
	test1();

	cout << "success" << endl;

	return 0;
}