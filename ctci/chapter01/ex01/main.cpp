#include<bits/stdc++.h>

using namespace std;

bool hasAllUniqueCharacters(string s) {
	int mask = 0;

	for(int i = 0; i < s.size(); i++) {
		int k = s[i] - 'a';
		if(mask & (1 << k)) {
			return false;
		}
		mask |= 1 << k;
	}

	return true;
}

int main() {
	assert(hasAllUniqueCharacters("") == true);
	assert(hasAllUniqueCharacters("a") == true);
	assert(hasAllUniqueCharacters("abcdefghijklmnopqrstuvwxyz") == true);

	assert(hasAllUniqueCharacters("aa") == false);
	assert(hasAllUniqueCharacters("aba") == false);
	assert(hasAllUniqueCharacters("abcdefghijklmnopqrstuvwxyza") == false);

	cout << "success" << endl;

	return 0;
}