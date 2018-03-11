#include<bits/stdc++.h>

using namespace std;

bool protectable(vector<string> &m, int row, int col) {
	int r = m.size();
	int c = m[0].size();
	if(row + 1 < r) {
		if(m[row+1][col] == 'W') {
			return false;
		}
	}
	if(row - 1 >= 0) {
		if(m[row-1][col] == 'W') {
			return false;
		}
	}
	if(col + 1 < c) {
		if(m[row][col+1] == 'W') {
			return false;
		}
	}
	if(col - 1 >= 0) {
		if(m[row][col-1] == 'W') {
			return false;
		}
	}
	return true;
}

void protect(vector<string> &m, int row, int col) {
	int r = m.size();
	int c = m[0].size();
	if(row + 1 < r && m[row+1][col] == '.') {
		m[row+1][col] = 'D';
	}
	if(row - 1 >= 0 && m[row-1][col] == '.') {
		m[row-1][col] = 'D';
	}
	if(col + 1 < c && m[row][col+1] == '.') {
		m[row][col+1] = 'D';
	}
	if(col - 1 >= 0 && m[row][col-1] == '.') {
		m[row][col-1] ='D';
	}
}

int main() {
	int r, c;
	
	while(cin >> r >> c) {
		vector<string> m(r);
		
		for(int i = 0; i < r; i++) {
			cin >> m[i];
		}
		
		bool ok = true;
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(m[i][j] == 'S' && !protectable(m, i, j)) {
					ok = false;
				}
			}
		}
		
		if(!ok) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(m[i][j] == 'S') {
						protect(m, i, j);
					}
				}
			}
			
			for(int i = 0; i < r; i++) {
				cout << m[i] << endl;
			}
		}
	}

	return 0;
}