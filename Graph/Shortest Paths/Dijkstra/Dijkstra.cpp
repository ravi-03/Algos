/*
	Dijkstra doesn't works for negative weight edges for undirected graphs &
	directed graphs as well.

	https://cp-algorithms.com/graph/dijkstra.html#implementation
	In this implementation we'are not marking vertices visited so its possible
	that for neg weight direct graph without any neg cycle this 
	will give correct result.
	
	consider an example input
	3
	3
	0
	0 1 5
	0 2 2
	1 2 -4
	This will give infinite loop
	https://bit.ly/3wSRbNU (StackOverflow)

	TC : O(VlogV + ElogV)
*/

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

const int INF = 1e9;

vector<vector<pair<int,int>>> adj; //adjacency list
vector<int> dist;
vector<int> parent;

void dijkstra(int src) {
	dist[src] = 0;

	priority_queue<pair<int,int>> pq; //default max heap
	pq.push({0,src});

	while(!pq.empty()) {
		auto ud = pq.top();
		pq.pop();
		int u = ud.second;
		int d = -1 * ud.first;

		//when we start looking for adj edges of u, 
		//dist[u] is at the best possible minimum value
		//so d can only be greater
		if(d != dist[u]) continue;

		for(auto vw : adj[u]) {
			int v = vw.first;
			int w = vw.second;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({-1 * dist[v], v}); //push negative weights for min heap
				parent[v] = u;
			}
		}
	}

}

vector<int> findPath(int v) {
	vector<int> path;
	for(int i = v; i != -1; i = parent[i]) {
		path.push_back(i);
	}
	reverse(path.begin(), path.end());
	return path;
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	int src; cin >> src;
	adj.resize(V);
	bool haveNegWeight = false;
	for(int i = 0; i < E; i++) {
		//0 based vertices
		int u, v, w; cin >> u >> v >> w;
		if(w < 0) {
			haveNegWeight = true;
		}
		adj[u].push_back({v, w}); 
		// adj[v].push_back({u, w});//undirected graph
	}
	dist.resize(V, INF);
	parent.resize(V, -1);

	if(haveNegWeight) {
		cout << "Dijkstra doesn't works for negative weight edges\n";
		return;
	}

	dijkstra(src);

	cout << "Shortest path from " << src << " to all nodes are : ";
	debug_vector(dist);

	cout << "Path from " << src << " to all vertices are : \n";
	for(int ver = 0; ver < V; ver++) {
		vector<int> path = findPath(ver);
		debug_vector(path);
	}
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
