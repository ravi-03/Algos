#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int src, vector<int> &ans) {
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty()) {
		int size = q.size(); //for keeping track of level/depth
		for(int i = 0; i < size; i++) {
			int u = q.front(); 
			q.pop();
			ans.push_back(u);
			for(int v : adj[u]) {
				if(!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
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
	bfs(src, ans);
	cout << "BFS traversal is : ";
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
