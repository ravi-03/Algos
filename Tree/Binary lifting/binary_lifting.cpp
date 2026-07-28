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

class KthAncestor {
	private:
		const int log2dist;
		vector<int> par;
		vector<vector<int>> pow2ends;


	public:
		KthAncestor(vector<int> &parent) : log2dist(ceil(log2(parent.size()))), 
		par(parent), pow2ends(par.size(), vector<int>(log2dist + 1)) {
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
};

void runTests() {
	// Example tree:
    //
    //         0
    //       /   \
    //      1     2
    //     / \   / \
    //    3  4  5   6
    //
    // parent[i] = parent of node i

    vector<int> parent = {
        -1, // 0
         0, // 1
         0, // 2
         1, // 3
         1, // 4
         2, // 5
         2  // 6
    };

    KthAncestor kth(parent);

    vector<pair<int, int>> queries = {
        {3, 1}, // 1
        {3, 2}, // 0
        {3, 3}, // -1
        {6, 1}, // 2
        {6, 2}, // 0
        {6, 3}, // -1
        {0, 1}  // -1
    };

    for (auto [node, k] : queries) {
        cout << k << "-th ancestor of node "
             << node << " = "
             << kth.getKthAncestor(node, k)
             << '\n';
    }
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1; 
	while(t--) runTests();
	return 0;
}
