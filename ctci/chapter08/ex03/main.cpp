#include<bits/stdc++.h>

using namespace std;

int findMagicIndex(vector<int> &a, int start, int end) {
	if(start >= end) {
		return -1;
	}

	int middle = start + (end - start) / 2;

	if(a[middle] == middle) {
		return middle;
	} else if(a[middle] > middle) {
		int leftResult = findMagicIndex(a, start, middle);
		if(leftResult >= 0) {
			return leftResult;
		}
	} else {
		int rightResult = findMagicIndex(a, middle + 1, end);
		if(rightResult >= 0) {
			return rightResult;
		}
	}

	return -1;
}

int findMagicIndex(vector<int> a) {
	return findMagicIndex(a, 0, a.size());
}

void test0() {
	vector<int> a = vector<int>({0, 2, 3, 4});

	int test = findMagicIndex(a);
	int control = 0;

	assert(test == control);
}

void test1() {
	vector<int> a = vector<int>({-1, 0, 1, 3});

	int test = findMagicIndex(a);
	int control = 3;

	assert(test == control);
}

void test2() {
	vector<int> a = vector<int>({-1, 0, 1, 2, 4, 8, 9});

	int test = findMagicIndex(a);
	int control = 4;

	assert(test == control);
}

int main() {
	test0();
	test1();
	test2();

	cout << "success" << endl;

	return 0;
}