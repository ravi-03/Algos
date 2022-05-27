#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj; //adjacency list
vector<int> status;
bool haveCycle = false;

void dfs(int u) {
	status[u] = 1; //put under processing
	for(int v : adj[u]) {
		if(status[v] == 0) {
			dfs(v);
		}
		if(status[v] == 1) {
			haveCycle = true;
			break;
		}
	}
	status[u] = 2;
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	adj.resize(V);
	status.resize(V, 0); //0 -> unvisited, 1 -> processing, 2 -> visited
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v; cin >> u >> v;
		adj[u].push_back(v); //directed graph
	}
	for(int i = 0; i < V; i++) {
		if(status[i] == 0) {
			dfs(i);
		}
	}
	if(haveCycle) {
		cout << "There is a cycle\n";
	} else {
		cout << "No cycle\n";
	}
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
