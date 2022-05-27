#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj; //adjacency list
vector<bool> visited;
bool haveCycle = false;

void bfs() {
	queue<pair<int,int>> q;
	q.push({0, -1});
	visited[0] = true;
	while(!q.empty()) {
		auto tmp = q.front();
		q.pop();
		for(int v : adj[tmp.first]) {
			if(!visited[v]) {
				q.push({v, tmp.first});
				visited[v] = true;
			} else {
				if (v != tmp.second) {
					haveCycle = true;
					return;
				}
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
	bfs();
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
