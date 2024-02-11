#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <stack>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> adj;
vector<int> disc;
vector<int> lowLink;
stack<int> st;
vector<bool> isInStack;
int timeVal;

void dfs(int u, vector<vector<int>> &scc) {
	cout << u << endl;
	disc[u] = lowLink[u] = ++timeVal;
	st.push(u);
	isInStack[u] = true;

	for (int v : adj[u]) {
		if (disc[v] == -1) {
			dfs(v, scc);
			lowLink[u] = min(lowLink[u], lowLink[v]);
		} else if (isInStack[v]) {
			lowLink[u] = min(lowLink[u], lowLink[v]);
		}
	}

	if (disc[u] == lowLink[u]) {
		//a scc found
		vector<int> ans;
		while (!st.empty() && st.top() != u) {
			ans.push_back(st.top());
			isInStack[st.top()] = false;
			st.pop();
		}	
		if (!st.empty()) {
			ans.push_back(st.top());
			isInStack[st.top()] = false;
			st.pop();
		}
		if (!ans.empty()) {
			scc.push_back(ans);
		}
	}
}

void tarjanScc() {
	int V; cin >> V;
	int E; cin >> E;

	adj.clear(); adj.resize(V);
	disc.clear(); disc.resize(V, -1);
	lowLink.clear(); lowLink.resize(V, -1);
	st = stack<int>();
	isInStack.clear(); isInStack.resize(V);
	timeVal = 0;

	for(int i = 0; i < E; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<vector<int>> allSccs;

	for (int i = 0; i < V; i++) {
		if (disc[i] == -1) {
			//seen for the first time
			dfs(i, allSccs);
		}
	}

	for (int x : disc) {
		cout << x << ' ';
	}
	cout << '\n';

	for (int x : lowLink) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << "All Sccs: " << endl;
	for (auto v : allSccs) {
		for (int x : v) {
			cout << x << ' ';
		}
		cout << endl;
	}

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) tarjanScc();
	return 0;
}
