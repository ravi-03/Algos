/*

Finds shortest path b/w all node pairs of graph in a single run.

Graph is stored in a adjacency matrix

Works for negative weight edges but not for negative weight cycles. It can
detect neg weight cycle if present.
For an undirected graph, a neg weight edge is considered as neg weight cycle.

But for all pairs of vertices i & j fro which there doesn't exist a path starting
at i visiting a neg weight cycle and ends at j, the algo still works correctly.

TC : O(|V|^3)
SC : O(|V|^2)

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int INF = 1e9;

vector<vector<int>> adj;
vector<vector<int>> dist;
bool haveNegWeightCycle = false;

void FloydWarshall() {

	int V = dist.size();

	for(int i = 0; i < V; i++) {
		dist[i][i] = 0;
	}

	for(int k = 0; k < V; k++) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				dist[i][j] =  min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// If distance of any vertex from itself
    // becomes negative, then there is a negative
    // weight cycle.
    for(int i = 0; i < V; i++) {
    	if(dist[i][i] < 0) {
    		haveNegWeightCycle = true;
    		break;
    	}
    }
}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;

	adj.resize(V, vector<int>(V, INF));

	for(int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = w;
		adj[v][u] = w; //undirected graphb
	}

	dist = adj;

	FloydWarshall();

	if(haveNegWeightCycle) {
		cout << "A neg weight cycle detected\n";
		return;
	}

	for(int i = 0; i < V; i++) {
		cout << "Shortest dist from " << i << " to every other node : ";
		for(int j = 0; j < V; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
