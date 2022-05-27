#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int src, vector<int> &ans) {
	visited[src] = true;
	ans.push_back(src);
	for(int x : adj[src]) {
		if(!visited[x]) {
			dfs(x, ans);
		}
	}
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
		adj[u].push_back(v);
		adj[v].push_back(u); //undirected graphs
	}
	vector<int> ans;
	dfs(src, ans);
	cout << "DFS traversal : ";
	for(int x : ans) {
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
