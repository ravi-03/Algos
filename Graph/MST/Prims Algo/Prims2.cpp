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

vector<vector<pair<int,int>>> adj;

void primsDenseImplementation(int V) {
	vector<int> key(V); //key[i] - minimum weight edge such that one end of edge is 
				//in mst set & other end conneting vertex i;
				//In case of dijkstra it was not weight instead it was distance 
				//from source to this vertex;

	vector<int> parent(V);
	vector<bool> visited(V);

	for(int i =  0; i < V; i++) {
		key[i] = INF, parent[i] = -1, visited[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	int total_weight = 0;

	//Initially there is no vertex in MST
	for(int i = 0; i < V; i++) {
		
		int u = -1;
		for(int j = 0; j < V; j++) {
			if(visited[j] == false && (u == -1 || key[j] < key[u])) {
				u = j;
			}
		}

		if(key[u] == INF) {
			cout << "No MST\n";
			return;
		}

		visited[u] = true;
		debug(u); //order in which each vertex is selected
		total_weight += key[u];

		for(auto e : adj[u]) {
			int v = e.first;
			int w = e.second;
			if(visited[v] == false && w < key[v]) {
				key[v] = w;
				parent[v] = u;
			}
		}
	}

	debug(total_weight);
	debug_vector(key);
	debug_vector(parent);

	//printing all the edges in mst
	//we started from 0, so parent of 0 is -1;
	cout << "Printing all the edges in MST \n";
	for(int i = 1; i < V; i++) {
		cout << parent[i] << ' ' << i << '\n';
	}

	//TC : 	O(V^2 + V + E)

}

void primsSparseImplementation(int V) {
	vector<int> key(V); //key[i] - minimum weight edge such that one end of edge is 
				//in mst set & other end conneting vertex i;
				//In case of dijkstra it was not weight instead it was distance 
				//from source to this vertex;

	vector<int> parent(V);
	vector<bool> visited(V);

	for(int i =  0; i < V; i++) {
		key[i] = INF, parent[i] = -1, visited[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	int total_weight = 0;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap
	pq.push({0,0}); //{weight, vertex}

	for(int i = 0; i < V - 1; i++) { //V - 1, as we not calculating toatal weight inside

		int u = pq.top().second;
		pq.pop();

		visited[u] = true;

		//Cannot do this here because piority queue can have edges, whose 
		//both ends are in MST set & we can't delete all of them. 
		//If we use set DS instead then its possible
		//by erasing the prev non-better values when line 118 satisfies. (erase() oper)
		// total_weight += key[u];

		for(auto e : adj[u]) {
			int v = e.first;
			int w = e.second;

			if(visited[v] == false && w < key[v]) {
				key[v] = w;
				parent[v] = u;
				pq.push({key[v], v});
			}
		}
	} 

	total_weight = accumulate(key.begin(), key.end(), 0LL);

	debug(total_weight);
	debug_vector(key);
	debug_vector(parent);

	//printing all the edges in mst
	//we started from 0, so parent of 0 is -1;
	cout << "Printing all the edges in MST \n";
	for(int i = 1; i < V; i++) {
		cout << parent[i] << ' ' << i << '\n';
	}

	//TC : O(VlogV + V + E) ~ O(VlogV) as number of edges 
	//are much smaller than number of vertices in sparse graphs.

}

void primsSparseSetImplementation(int V) {
	vector<int> key(V); //key[i] - minimum weight edge such that one end of edge is 
				//in mst set & other end conneting vertex i;
				//In case of dijkstra it was not weight instead it was distance 
				//from source to this vertex;

	vector<int> parent(V);
	vector<bool> visited(V);

	for(int i =  0; i < V; i++) {
		key[i] = INF, parent[i] = -1, visited[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	int total_weight = 0;

	set<pair<int,int>> see; //min heap
	see.insert({0,0}); //{weight, vertex}

	for(int i = 0; i < V; i++) {

		int u = see.begin() -> second;
		see.erase(see.begin());

		visited[u] = true;
		total_weight += key[u];

		for(auto e : adj[u]) {
			int v = e.first;
			int w = e.second;

			if(visited[v] == false && w < key[v]) {
				see.erase({key[v], v});
				key[v] = w;
				parent[v] = u;
				see.insert({key[v], v});
			}
		}
	} 

	debug(total_weight);
	debug_vector(key);
	debug_vector(parent);

	//printing all the edges in mst
	//we started from 0, so parent of 0 is -1;
	cout << "Printing all the edges in MST \n";
	for(int i = 1; i < V; i++) {
		cout << parent[i] << ' ' << i << '\n';
	}

	//TC : O(VlogV + V + E) ~ O(VlogV) as number of edges 
	//are much smaller than number of vertices in sparse graphs.

}

void runTests() {
	int V; cin >> V;
	int E; cin >> E;

	adj.resize(V);

	for(int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); 
	}

	cout << "Dense graph implementation\n";
	primsDenseImplementation(V);
	cout << "\nSparse graph implementation\n";
	primsSparseImplementation(V);
	cout << "\nSparse graph Set implementation\n";
	primsSparseSetImplementation(V);

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
