#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define debug(x) cout << #x << " : " << x << '\n';

template <class T> void debug_vector(vector<T> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

vector<vector<int>> adj; //adjacency list
vector<int> color;
bool isPossible = true;

void bfs(int src) {
	color[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]) {
			if(color[v] == -1) {
				q.push(v);
				color[v] = color[u] ^ 1;
			}
			if(color[v] == color[u]) {
				isPossible = false;
				return;
			}
		}
	}
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	adj.resize(V);
	color.resize(V, -1);
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v; cin >> u >> v;
		adj[u].push_back(v); 
		adj[v].push_back(u);//undirected graph
	}
	//color all the vertices using only 2 colors (using 0 & 1)
	bfs(2);
	if(isPossible) {
		cout << "Coloring is : ";
		debug_vector(color);
		vector<int> set1, set2;
		for(int i = 0; i < V; i++) {
			if(color[i] == 0) {
				set1.push_back(i);
			} else {
				set2.push_back(i);
			}
		}
		cout << "Set1 vertices : ";
		debug_vector(set1);
		cout << "Set2 vertices : ";
		debug_vector(set2);
	} else {
		cout << "No Coloring possible\n";
	}
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
