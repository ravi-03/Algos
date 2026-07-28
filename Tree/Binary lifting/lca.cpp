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

#ifndef ONLINE_JUDGE
// #include "../debug.h"
#else
#define debug(...) 42
#endif

#define int long long

const int MOD = 1e9 + 7;
 
void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
}
 
int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
	return a;
}
 
int mul(int a, int b) {
	return a * b % MOD;
}
 
int power(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y = y >> 1;
	}
	return ans;
}

class LCA {
	private:
		const int root;
		const int log2dist;
		vector<int> par;
		vector<vector<int>> pow2ends;
		vector<int> depth;
		vector<vector<int>> adj;

		void buildAdj() {
			adj.resize(par.size());
			for (int i = 0; i < par.size(); i++) {
				if (par[i] != -1) {
					adj[par[i]].push_back(i);
					adj[i].push_back(par[i]);
				}
			}
		}

		void calculateDepth(int at, int prev) {
			if (prev != -1) {
				depth[at] = depth[prev] + 1;
			}
			for (int v: adj[at]) {
				if (v == prev) continue;
				calculateDepth(v, at);
			}
		}

		void preprocess() {
			buildAdj();
			calculateDepth(root, -1);
		}

	public:
		LCA(int root, vector<int> &parent) : root(root), log2dist(ceil(log2(parent.size()))), 
		par(parent), pow2ends(par.size(), vector<int>(log2dist + 1)), depth(par.size()) {
			preprocess();
			// 0-based indexing.
			for (int node = 0; node < par.size(); node++) {
				pow2ends[node][0] = par[node];
			}
			for (int p = 1; p <= log2dist; p++) {
				for (int node = 0; node < par.size(); node++) {
					int halfway = pow2ends[node][p - 1];
					if (halfway == -1) {
						pow2ends[node][p] = -1;
					} else {
						pow2ends[node][p] = pow2ends[halfway][p - 1];
					}
				}
			}
		}

		int getKthAncestor(int node, int k) {
			int at = node;
			for (int i = 0; i <= log2dist; i++) {
				if (((1 << i) & k) != 0) {
					at = pow2ends[at][i];
					if (at == -1) {
						break;
					}
				}
			}
			return at;
		}

		int lca(int n1, int n2) {
			if (depth[n1] < depth[n2]) {
				return lca(n2, n1);
			}
			n1 = getKthAncestor(n1, depth[n1] - depth[n2]);
			if (n1 == n2) {
				return n1;
			}
			for (int i = log2dist; i >= 0; i--) {
			    if (pow2ends[n1][i] != -1 &&
			        pow2ends[n1][i] != pow2ends[n2][i]) {
			        n1 = pow2ends[n1][i];
			        n2 = pow2ends[n2][i];
			    }
			}
			return pow2ends[n1][0];
		}
};

void runTests() {
	/*
            0
         /  |  \
        1   2   3
       / \      \
      4   5      6
         / \
        7   8
    */

    vector<int> parent = {
        -1, // 0
         0, // 1
         0, // 2
         0, // 3
         1, // 4
         1, // 5
         3, // 6
         5, // 7
         5  // 8
    };

    LCA lca(0, parent);

    auto test = [&](int u, int v, int expected) {
        int ans = lca.lca(u, v);

        cout << "LCA(" << u << ", " << v << ") = "
             << ans << " ";

        if (ans == expected)
            cout << "Correct.";
        else
            cout << "Expected " << expected;

        cout << '\n';
    };

    // root
    test(0, 0, 0);

    // same node
    test(7, 7, 7);

    // parent-child
    test(5, 8, 5);

    // siblings
    test(4, 5, 1);

    // cousins
    test(4, 6, 0);

    // different subtrees
    test(2, 8, 0);

    // one ancestor
    test(1, 7, 1);

    // leaves
    test(7, 8, 5);

    // root with leaf
    test(0, 8, 0);

    // another subtree
    test(6, 3, 3);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1; 
	while(t--) runTests();
	return 0;
}
