#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

vvi& zeroMatrix2(vvi &m) {
	unordered_set<int> rows;
	unordered_set<int> cols;

	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++)  {
			if(m[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++) {
			if(rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
				m[i][j] = 0;
			}
		}
	}

	return m;
}

vvi& zeroMatrix(vvi &m) {
	bool firstRowHasZero = false;
	bool firstColHasZero = false;

	for(int i = 0; i < m.size(); i++) {
		if(m[i][0] == 0) {
			firstColHasZero = true;
		}
	}

	for(int k = 0; k < m[0].size(); k++) {
		if(m[0][k] == 0) {
			firstRowHasZero = true;
		}
	}

	for(int i = 1; i < m.size(); i++) {
		for(int k = 1; k < m[i].size(); k++) {
			if(m[i][k] == 0) {
				m[0][k] = 0;
				m[i][0] = 0;
			}
		}
	}

	for(int i = 1; i < m.size(); i++) {
		for(int k = 1; k < m[i].size(); k++) {
			if(m[i][0] == 0 || m[0][k] == 0) {
				m[i][k] = 0;
			}
		}
	}

	if(firstColHasZero) {
		for(int i = 0; i < m.size(); i++) {
			m[i][0] = 0;
		}
	}

	if(firstRowHasZero) {
		for(int k = 0; k < m[0].size(); k++) {
			m[0][k] = 0;
		}
	}

	return m;
}

int main() {
	vvi m;

	m = vvi({{0}});
	assert(zeroMatrix(m) == vvi({{0}}));

	m = vvi({{0, 1}});
	assert(zeroMatrix(m) == vvi({{0, 0}}));

	m = vvi({{0}, {1}});
	assert(zeroMatrix(m) == vvi({{0}, {0}}));

	m = vvi({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
	assert(zeroMatrix(m) == vvi({{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}));

	cout << "success" << endl;

	return 0;
}