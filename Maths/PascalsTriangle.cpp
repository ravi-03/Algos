#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

int n;
vector<vector<int>> comb;

void pascal() {
	for(int i = 0; i <= n; i++) {
		comb[i] = vector<int>(i + 1, 1);
		for(int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

void runTests() {
	cin >> n;
	comb.resize(n + 1);

	pascal();

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < i + 1; j++) {
			cout << comb[i][j] << ' ';
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
