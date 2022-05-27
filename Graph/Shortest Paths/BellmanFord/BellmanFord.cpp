/*

Single source shortest path algo (SSSP)

Works for negative weight edges but not for negative weight cycles. It can
detect neg weight cycle if present.
For an undirected graph, a neg weight edge is considered as neg weight cycle.

TC : O(V*E)

Graph is stored as an edge-list of the form (u,v,w) -> there is an edge from u to v
with weight w.

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

vector<vector<int>> edges;
vector<int> dist;
bool haveNegWeightCycle = false;

void BellmanFord(int src, int V) {

	dist[src] = 0;

	for(int i = 1; i <= V - 1; i++) {
		for(auto e : edges) {
			int u = e[0], v = e[1], w = e[2];
			dist[v] = min(dist[v], dist[u] + w);
		}
	}

	//detecting neg weight cycle
	for(auto e : edges) {
		int u = e[0], v = e[1], w = e[2];
		if(dist[u] + w < dist[v]) {
			haveNegWeightCycle = true;
			break;
		}
	}

}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;
	int src; cin >> src;

	for(int i = 0; i < E; i++) {
		vector<int> inp(3);
		cin >> inp[0] >> inp[1] >> inp[2];
		edges.push_back(inp);
		edges.push_back({inp[1], inp[0], inp[2]}); //undirected graph
	}

	dist.resize(V, INF);

	BellmanFord(src, V);

	if(haveNegWeightCycle) {
		cout << "A Negative weight cycle is detected\n";
		return;
	}

	cout << "Shorted distance from " << src << " to all other vertices : ";
	debug_vector(dist);
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
