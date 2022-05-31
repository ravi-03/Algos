#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> transpose;

void dfs(int u, stack<int> &topo) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			dfs(v, topo);
		}
	}
	topo.push(u);
}

void revDfs(int u) {
	visited[u] = true;
	cout << u << ' '; 
	for(int v : transpose[u]) {
		if(!visited[v]) {
			revDfs(v);
		}
	}
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	adj.resize(V);
	visited.resize(V);
	for(int i = 0; i < E; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	//get the topological ordering(not exactly as graph may contain cycles)
	//topological ordering of SCCs
	stack<int> topo;

	for(int i = 0; i < V; i++) {
		if(!visited[i]) {
			dfs(i, topo);
		}
	}

	//transpose the graph
	transpose.resize(V);
	for(int i = 0; i < V; i++) {
		for(int v : adj[i]) {
			transpose[v].push_back(i);
		}
	}

	//unmark visited array
	visited.assign(V, false);

	cout << "SCCs are : \n";

	//apply dfs on the transpose of the graph in order stored by stack
	while(!topo.empty()) {
		int u = topo.top();
		topo.pop();
		if(!visited[u]) {
			revDfs(u);
			cout << '\n';
		}
	}

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
