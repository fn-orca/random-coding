#include<bits/stdc++.h>

using namespace std;

bool isSubstring(string &s, string &query) {
	return s.find(query) != string::npos;
}

bool isRotation(string s1, string s2) {
	if(s1.size() != s2.size()) {
		return false;
	}
	
	s1 += s1;
	return isSubstring(s1, s2);
}

int main() {
	assert(isRotation("apple", "pplea") == true);
	assert(isRotation("aa", "aa") == true);
	assert(isRotation("abc", "cab") == true);
	assert(isRotation("a", "a") == true);
	assert(isRotation("", "") == true);

	assert(isRotation("abc", "cba") == false);
	assert(isRotation("apple", "elapp") == false);
	assert(isRotation("apple", "leapple") == false);

	cout << "success" << endl;

	return 0;
}