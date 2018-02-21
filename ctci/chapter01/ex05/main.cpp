#include<bits/stdc++.h>

using namespace std;

int myAbs(int n) {
	return n >= 0 ? n : -n;
}

bool oneAwayDiffSize(string s1, string s2) {
	if(s1.size() > s2.size()) {
		swap(s1, s2);
	}

	bool diffFound = false;

	int i = 0;

	for(int k = 0; k < s2.size(); k++) {
		if(i >= s1.size()) {
			break;
		}

		if(s1[i] != s2[k]) {
			if(diffFound) {
				return false;
			}

			diffFound = true;
		} else {
			i++;
		}
	}

	return true;
}

bool oneAwaySameSize(string s1, string s2) {
	bool diffFound = false;

	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] != s2[i]) {
			if(diffFound) {
				return false;
			}

			diffFound = true;
		}
	}

	return true;
}

bool oneAway(string s1, string s2) {
	if(myAbs(s1.size() - s2.size()) > 1) {
		return false;
	}

	if(s1.size() != s2.size()) {
		return oneAwayDiffSize(s1, s2);
	} else {
		return oneAwaySameSize(s1, s2);
	}
}

int main() {
	assert(oneAway("pale", "ple") == true);
	assert(oneAway("pales", "pale") == true);
	assert(oneAway("pale", "bale") == true);
	assert(oneAway("lap", "la") == true);
	assert(oneAway("ap", "lap") == true);
	assert(oneAway("lap", "laap") == true);
	assert(oneAway("lap", "lcp") == true);

	assert(oneAway("pale", "bake") == false);
	assert(oneAway("lap", "laaap") == false);

	cout << "success" << endl;

	return 0;
}