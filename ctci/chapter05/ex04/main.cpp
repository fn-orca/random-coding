#include<bits/stdc++.h>

using namespace std;

// original
// 0 0 1 1 0 1 0 0 1 1 1 0
// next
// 0 0 1 1 0 1 0 1 0 0 1 1
// prev
// 0 0 1 1 0 0 1 1 0

int getNext(int n) {
	int maxi = (1 << 30) | ((1 << 30) - 1); 
	if(n == 0 || n == maxi) {
		return n;
	}

	int ans = n;
	int i = 0;
	int onesCount = 0;

	while(i < 32) {
		int bit = n & 1;

		if(bit == 0) {
			if(onesCount) {
				ans |= 1 << i;
				ans &= ans - 1;
				ans |= (1 << (onesCount - 1)) - 1;
				break;
			}
		}
		if(bit == 1) {
			onesCount++;
		}

		n >>= 1;
		i++;
	}

	return ans;
}

int getPrev(int n) {
	int maxi = (1 << 30) | ((1 << 30) - 1); 
	if(n == 0 || n == maxi) {
		return n;
	}

	int ans = n;
	int i = 0;
	int zeroesCount = 0;

	while(i < 32) {
		int bit = n & 1;

		if(bit == 0) {
			zeroesCount++;
		}
		if(bit == 1) {
			if(zeroesCount) {
				int aux = (1 << i) - 1;
				aux = ~aux;
				ans &= aux;
				ans ^= 1 << i;
				zeroesCount--;
				int onesCount = i - zeroesCount + 1;
				int mask = (1 << onesCount) - 1;
				mask <<= zeroesCount;
				ans |= mask;
				break;
			}
		}

		n >>= 1;
		i++;
	}

	return ans;

}

void test0() {
	int n = 0;
	int testNext = getNext(n);
	int controlNext = n;
	assert(testNext == controlNext);

	int testPrev = getPrev(n);
	int controlPrev = n;
	assert(testPrev == controlPrev);
}

void test1() {
	int n = (1 << 30) | ((1 << 30) - 1);
	int testNext = getNext(n);
	int controlNext = n;
	assert(testNext == controlNext);
	
	int testPrev = getPrev(n);
	int controlPrev = n;
	assert(testPrev == controlPrev);
}

void test2() {
	int n = 0b0101;
	int testNext = getNext(n);
	int controlNext = 0b0110;
	assert(testNext == controlNext);
	
	int testPrev = getPrev(n);
	int controlPrev = 0b0011;
	assert(testPrev == controlPrev);
}

void test3() {
	int n = 0b011;
	int testNext = getNext(n);
	int controlNext = 0b101;
	assert(testNext == controlNext);
	
	int testPrev = getPrev(n);
	int controlPrev = 0b011;
	assert(testPrev == controlPrev);
}

void test4() {
	int n = 0b10;
	int testNext = getNext(n);
	int controlNext = 0b10;
	assert(testNext == controlNext);
	
	int testPrev = getPrev(n);
	int controlPrev = 0b01;
	assert(testPrev == controlPrev);
}

void test5() {
	int n = 0b100100110;
	int testNext = getNext(n);
	int controlNext = 0b100101001;
	assert(testNext == controlNext);
	
	int testPrev = getPrev(n);
	int controlPrev = 0b100100110;
	assert(testPrev == controlPrev);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();

	cout << "success" << endl;

	return 0;
}