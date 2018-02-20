#include<bits/stdc++.h>

using namespace std;

bool isPermutOfPalin(string s) {
	unordered_map<char, int> m;

	for(auto& c : s) {
		if(c == ' ') {
			continue;
		}

		m[c]++;
	}

	int odd = 0;

	for(auto it = m.begin(); it != m.end(); it++) {
		if(it->second % 2 != 0) {
			odd++;
		}
	}

	if(odd > 1) {
		return false;
	}

	return true;
}

int main() {
	assert(isPermutOfPalin("tact coa") == true);
	assert(isPermutOfPalin("a b c b a") == true);
	assert(isPermutOfPalin("a") == true);
	assert(isPermutOfPalin("abba") == true);
	assert(isPermutOfPalin("aba") == true);
	assert(isPermutOfPalin("") == true);

	assert(isPermutOfPalin("a b c b a d") == false);
	assert(isPermutOfPalin("ab bb") == false);
	assert(isPermutOfPalin("ca") == false);

	cout << "success" << endl;

	return 0;
}