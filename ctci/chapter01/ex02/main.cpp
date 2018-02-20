#include<bits/stdc++.h>

using namespace std;

bool arePermutationsOfEachOther(string s1, string s2) {
	if(s1.size() != s2.size()) {
		return false;
	}

	unordered_map<char, int> m1;
	unordered_map<char, int> m2;

	for(int i = 0; i < s1.size(); i++) {
		m1[s1[i]]++;
		m2[s2[i]]++;
	}

	return m1 == m2;
}

int main() {
	assert(arePermutationsOfEachOther("", "") == true);
	assert(arePermutationsOfEachOther("a", "a") == true);
	assert(arePermutationsOfEachOther("abc", "cab") == true);
	assert(arePermutationsOfEachOther("aaa", "aaa") == true);

	assert(arePermutationsOfEachOther("", "a") == false);
	assert(arePermutationsOfEachOther("b", "a") == false);
	assert(arePermutationsOfEachOther("aa", "a") == false);

	cout << "success" << endl;

	return 0;
}