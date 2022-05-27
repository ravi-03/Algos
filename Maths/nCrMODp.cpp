#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int P = 1e9 + 7;

int nCrMODp(int n, int r) {
	if(r > n - r) 
		r = n - r;
	vector<int> C(r + 1, 0);
	C[0] = 1;

	//making pascal triangle till n + 1;
	for(int i = 1; i <= n; i++) {
		for(int j = min(i, r); j > 0; j--) {
			C[j] = (C[j] + C[j - 1]) % P;
		}
	}
	return C[r];

	//TC : O(n * r)
}

void runTests() {
	int n, r; cin >> n >> r;
	cout << nCrMODp(n, r) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
