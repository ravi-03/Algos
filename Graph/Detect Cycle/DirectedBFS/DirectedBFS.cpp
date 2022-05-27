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

vector<vector<int>> adj;
vector<int> indeg;
int cnt = 0;

void bfs() {

	//calculate indeg of every vertex
	for(auto u : adj) {
		for(int v : u) {
			indeg[v]++;
		}
	}

	debug_vector(indeg);

	queue<int> q;
	for(int i = 0; i < indeg.size(); i++) {
		if(indeg[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			int u = q.front();
			q.pop();
			for(int v : adj[u]) {
				//reduce indeg of every adj vertices by 1
				indeg[v]--;
				if(indeg[v] == 0) {
					q.push(v);
				}
			}
			cnt++;
		}
	}
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	adj.resize(V);
	indeg.resize(V);
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v; cin >> u >> v;
		adj[u].push_back(v); //directed graph
	}
	bfs();
	if(cnt != V) {
		cout << "There is a cycle in the graph\n";
	} else {
		cout << "No Cycle\n";
	}
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
