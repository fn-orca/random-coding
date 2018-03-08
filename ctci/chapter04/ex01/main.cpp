#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;

void dfs(graph &g, vector<bool> &seen, int u) {
	if(seen[u]) {
		return;
	}

	seen[u] = true;

	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(g, seen, v);
	}
}

bool existsPathBetween(graph &g, int from, int to) {
	vector<bool> seen(g.size(), false);

	dfs(g, seen, from);

	return seen[to];
}

int main() {
	graph g(5);
	g[0].push_back(1);
	g[0].push_back(2);
	g[2].push_back(0);
	g[2].push_back(3);
	g[3].push_back(2);
	g[3].push_back(4);

	assert(existsPathBetween(g, 0, 4) == true);
	assert(existsPathBetween(g, 2, 4) == true);
	assert(existsPathBetween(g, 3, 4) == true);

	assert(existsPathBetween(g, 0, 1) == true);
	assert(existsPathBetween(g, 0, 2) == true);
	assert(existsPathBetween(g, 0, 3) == true);

	assert(existsPathBetween(g, 3, 2) == true);
	assert(existsPathBetween(g, 3, 0) == true);
	assert(existsPathBetween(g, 2, 0) == true);

	assert(existsPathBetween(g, 1, 0) == false);
	assert(existsPathBetween(g, 4, 0) == false);
	assert(existsPathBetween(g, 4, 2) == false);
	assert(existsPathBetween(g, 4, 3) == false);
	assert(existsPathBetween(g, 4, 1) == false);

	cout << "success" << endl;

	return 0;
}