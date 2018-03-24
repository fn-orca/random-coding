#include<bits/stdc++.h>

using namespace std;

int countWays(int n) {
	if(n == 0) {
		return 1;
	}

	vector<int> dp(n + 1, 0);

	dp[0] = 1;

	for(int i = 0; i < n; i++) {
		for(int k = 1; k <= 3; k++) {
			if(i + k < dp.size()) {
				dp[i + k] += dp[i];
			}
		}
	}

	return dp[n];
}

void test0() {
	int n = 1;

	int test = countWays(n);
	int control = 1;

	assert(test == control);
}

void test1() {
	int n = 2;

	int test = countWays(n);
	int control = 2;

	assert(test == control);
}

void test2() {
	int n = 3;

	int test = countWays(n);
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