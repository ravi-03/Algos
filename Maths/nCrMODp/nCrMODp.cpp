#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int P = 1e9 + 7;

int power(int x, int y) {
	if (y == 0) {
		return 1;
	}
	if (x == 0) {
		return 0;
	}
	assert(y > 0);
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans *= x;
			ans %= P;
		}
		x = x * x % P;
		y = y >> 1;
	}
	return ans;
	//TC: O(log2(y))
}

int nCrMODp2(int n, int r) {
	if (r > n - r) {
		r = n - r;
	}
	//nCr = (n * n - 1 * .... * n - r + 1) / fact(r)
	int num = 1;
	for (int i = n; i >= n - r + 1; i--) {
		num *= i;
		num %= P;
	}
	int den = 1;
	for (int i = r; i >= 1; i--) {
		den *= i;
		den %= P;
	}
	//using fermat's little theorem
	return num * power(den, P - 2) % P;
	//TC: O(n)
}

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
	cout << nCrMODp2(n, r) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
