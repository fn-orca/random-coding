#include<bits/stdc++.h>

using namespace std;

string& replaceSpaces(string &s, int fakeSize) {
	int numberOfSpaces = 0;

	for(int i = 0; i < fakeSize; i++) {
		if(s[i] == ' ') {
			numberOfSpaces++;
		}
	}

	int realSize = fakeSize + numberOfSpaces*2;
	int k = realSize - 1;
	int i = fakeSize - 1;

	while(i >= 0) {
		if(s[i] == ' ') {
			s[k] = '0';
			s[k-1] = '2';
			s[k-2] = '%';
			k = k - 3;
			i--;
		} else {
			s[k] = s[i];
			k--;
			i--;
		}
	}

	return s;
}

int main() {
	string a;
	
	a = "   ";
	assert(replaceSpaces(a, 1) == "%20");

	a = "a b  ";
	assert(replaceSpaces(a, 3) == "a%20b");

	a = " a  ";
	assert(replaceSpaces(a, 2) == "%20a");

	a = "a   ";
	assert(replaceSpaces(a, 2) == "a%20");

	cout << "success" << endl;

	return 0;
}