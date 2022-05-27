#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj; //adjacency list
vector<bool> visited;
bool haveCycle = false;

void dfs(int u, int parentOfU) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			dfs(v, u);
		} else {
			//already visited vertex should not be its adjacent node(parent node);
			if(v != parentOfU) {
				haveCycle = true;
				break;
			}
		}
	}
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	adj.resize(V);
	visited.resize(V, false);
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v; cin >> u >> v;
		adj[u].push_back(v); 
		adj[v].push_back(u);//undirected graph
	}
	for(int i = 0; i < V; i++) {
		if(!visited[i]) {
			dfs(i, -1);
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
