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

const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

int n;
vector<vector<int>> adj; // adjacency matrix of graph

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        debug(i);
        debug(v);

        for(int i = 0; i < n; i++) {
            cout << min_e[i].w << ' ' << min_e[i].to << '\n';
        }
        debug(v);

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w) {
            	Edge ed;
           		ed.w = adj[v][to];
           		ed.to = v;
                min_e[to] = ed;
            }
        }
        debug(total_weight);
        debug_vector(selected);
        debug(v);
        for(int i = 0; i < n; i++) {
            cout << min_e[i].w << ' ' << min_e[i].to << '\n';
        }
        debug(v);
    }

    cout << total_weight << endl;
}


void runTests() {
    debug(n);
	int V; cin >> V; n = V;
	int E; cin >> E;

	adj.resize(V, vector<int>(V, INF));

	for(int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = w;
		adj[v][u] = w; //undirected graph
	}

	prim();
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
