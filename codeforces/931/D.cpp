#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> inv;
map<int, vector<int>> m;

void dfs(int u, int currentLevel) {
	m[-currentLevel].push_back(u);

	for(int i = 0; i < inv[u].size(); i++) {
		dfs(inv[u][i], currentLevel + 1);
	}
}

int main() {
	int n;

	while(cin >> n) {
		vector<vector<int>> g(n);
		inv = vector<vector<int>>(n);

		for(int i = 1; i < n; i++) {
			int p;

			cin >> p;

			g[i].push_back(p - 1);
			inv[p - 1].push_back(i);
		}

		m.clear();
		dfs(0, 0);



		int ans = 1;

		

		cout << ans << endl;
	}

	return 0;
}