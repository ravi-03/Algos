#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj; //adjacency list
vector<bool> visited;
bool haveCycle = false;

void dfs(int u, vector<int> &topo) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			dfs(v, topo);
		} else {
			haveCycle = true;
		}
	}
	topo.push_back(u); //every child node is visited before this node;
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	int src; cin >> src;
	adj.resize(V);
	visited.resize(V, false);
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v; cin >> u >> v;
		adj[u].push_back(v); //directed graph
	}
	vector<int> topo;
	dfs(src, topo);
	reverse(topo.begin(), topo.end());
	if(haveCycle) {
		cout << "This graph contains cycle\n";
		return;
	}
	cout << "Topological order is : ";
	for(int x : topo) {
		cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
