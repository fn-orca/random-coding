#include<bits/stdc++.h>

using namespace std;

struct result {
	bool isOk;
	vector<int> buildOrder;

	result(bool _isOk, vector<int> _buildOrder) {
		isOk = _isOk;
		buildOrder = _buildOrder;
	}
};

typedef vector<vector<int>> graph;

const int NOT_VISITED = 0;
const int VISITING = 1;
const int VISITED = 2;

vector<int> status;
vector<int> topo;
bool hasCycle;

void dfs(graph &g, int u) {
	if(status[u] == VISITED) {
		return;
	}
	if(status[u] == VISITING) {
		hasCycle = true;
		return;
	}

	status[u] = VISITING;

	for(int j = 0; j < g[u].size(); j++) {
		int v = g[u][j];
		dfs(g, v);
	}

	status[u] = VISITED;

	topo.push_back(u);
}

result getBuildOrder(graph &g) {
	topo.clear();
	status = vector<int>(g.size());
	hasCycle = false;

	for(int i = 0; i < g.size(); i++) {
		if(status[i] == NOT_VISITED) {
			dfs(g, i);
		}
	}

	reverse(topo.begin(), topo.end());

	return result(hasCycle == false, topo);
}

int main() {
	cout << "success" << endl;

	return 0;
}