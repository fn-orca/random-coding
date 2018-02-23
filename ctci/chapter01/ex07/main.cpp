#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

void printMatrix(vvi &m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

vvi& rotate(vvi &m) {
	int n = m.size();
	for(int offset = 0; offset < n/2; offset++) {
		for(int i = 0; i < n - offset*2 - 1; i++) {
			int &a = m[offset][offset + i];
			int &b = m[offset + i][n-offset-1];
			int &c = m[n-offset-1][n-offset-i-1];
			int &d = m[n-offset-i-1][offset];

			int temp = a;
			a = d;
			d = c;
			c = b;
			b = temp;
		}
	}

	return m;
}

int main() {
	vvi m;

	m = vvi({{1, 2},{3, 4}});
	assert(rotate(m) == vvi({{3, 1}, {4, 2}}));

	m = vvi({{1, 1, 1}, {2, 2, 2}, {3, 3, 3}});
	assert(rotate(m) == vvi({{3, 2, 1}, {3, 2, 1}, {3, 2, 1}}));
	
	m = vvi({{1}});
	assert(rotate(m) == vvi({{1}}));
	
	m = vvi();
	assert(rotate(m) == vvi());

	cout << "success" << endl;

	return 0;
}