#include<bits/stdc++.h>

using namespace std;

int countCompression(string s) {
	int compressedSize = 0;

	int count = 0;
	for(int i = 0; i < s.size(); i++) {
		count++;

		if(i + 1 >= s.size() || s[i] != s[i+1]) {
			count += 1 + log10(count) + 1;
		}
	}

	return compressedSize;
}

string compress(string s) {
	int finalSize = countCompression(s);

	if(s.size() <= finalSize) {
		return s;
	}

	string ret = "";

	int count = 0;
	for(int i = 0; i < s.size(); i++) {
		count++;

		if(i + 1 >= s.size() || s[i] != s[i+1]) {
			ret += s[i];
			ret += count + '0';
			count = 0;
		}
	}

	return ret.size() < s.size() ? ret : s;
}

int main() {
	assert(compress("") == "");
	assert(compress("abc") == "abc");
	assert(compress("abbc") == "abbc");
	assert(compress("aaaaaaabc") == "a7b1c1");
	assert(compress("abccccccc") == "a1b1c7");
	assert(compress("abbbbbbbc") == "a1b7c1");
	assert(compress("aaaaaaa") == "a7");

	cout << "success" << endl;

	return 0;
}