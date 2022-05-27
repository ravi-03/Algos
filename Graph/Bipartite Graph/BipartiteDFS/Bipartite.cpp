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

void dfs(int src, int col) {
	color[src] = col;
	for(int v : adj[src]) {
		if(color[v] == -1) {
			dfs(v, col ^ 1);
		}
		if(color[v] == col) {
			//not possible to color
			isPossible = false;
			return;
		}
	}
}

void dfs2(int src) {
	//this node is already colored
	int src_col = color[src];
	for(int v : adj[src]) {
		if(color[v] == -1) {
			dfs(v, src_col ^ 1);
		}
		if(color[v] == src_col) {
			//not possible
			isPossible = false;
			return;
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
	dfs(0, 0);
	// color[0] = 0;
	// dfs2(0);
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
