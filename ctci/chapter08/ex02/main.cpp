#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class solver {
	vector<vector<int>> g;
	int r;
	int c;

public:
	solver(vector<vector<int>> g) {
		this-> g = g;
		r = g.size();
		c = g[0].size();
	}

	vector<ii> findPath() {
		g[0][0] = 1;

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(g[i][j] < 0) {
					continue;
				}

				if(j - 1 >= 0) {
					g[i][j] += g[i][j-1] > 0 ? g[i][j-1] : 0;
				}
				if(i - 1 >= 0) {
					g[i][j] += g[i-1][j] > 0 ? g[i-1][j] : 0;
				}
			}
		}

		if(g[r-1][c-1] == 0) {
			return vector<ii>();
		}

		int R = r - 1;
		int C = c - 1;

		vector<ii> path;

		while(R || C) {
			path.push_back(ii(R, C));

			if(R - 1 >= 0) {
				if(g[R - 1][C] > 0) {
					R = R - 1;
					continue;
				}
			}

			if(C - 1 >= 0) {
				if(g[R][C - 1] > 0) {
					C = C - 1;
					continue;
				}
			}
		}

		path.push_back(ii(0, 0));

		reverse(path.begin(), path.end());

		return path;
	}
};

void printGraph(vector<vector<int>> g) {
	for(int i = 0; i < g.size(); i++) {
		for(int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}

		cout << endl;
	}
}

void printPath(vector<ii> path) {
	if(path.size() == 0) {
		cout << "NO PATH" << endl;
	}

	for(int i = 0; i < path.size(); i++) {
		if(i) {
			cout << "->";
		}

		cout << "(" << path[i].first << ", " << path[i].second << ")";
	}

	cout << endl;
}

void test0() {
	int r = 1;
	int c = 1;

	vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c, 0));

	cout << "Test case 0:" << endl;

	printGraph(g);

	cout << endl;

	solver s = solver(g);

	printPath(s.findPath());

	cout << endl;
}

void test1() {
	int r = 2;
	int c = 2;

	vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c, 0));

	g[0][1] = -1;

	cout << "Test case 1:" << endl;

	printGraph(g);

	cout << endl;

	solver s = solver(g);

	printPath(s.findPath());

	cout << endl;
}

void test2() {
	int r = 2;
	int c = 2;

	vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c, 0));

	g[1][0] = -1;

	cout << "Test case 2:" << endl;

	printGraph(g);

	cout << endl;

	solver s = solver(g);

	printPath(s.findPath());

	cout << endl;
}

void test3() {
	int r = 2;
	int c = 2;

	vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c, 0));

	g[0][1] = -1;
	g[1][0] = -1;

	cout << "Test case 3:" << endl;

	printGraph(g);

	cout << endl;

	solver s = solver(g);

	printPath(s.findPath());

	cout << endl;
}

int main() {
	test0();
	test1();
	test2();
	test3();

	cout << "success" << endl;

	return 0;
}