#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int P = 1e9 + 7;

//https://bit.ly/3arkxeS (GFG)
//using inverse to find nCr mod P

int power(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) {
			ans = ans * x % P;
		}
		y = y >> 1;
		x = (x * x) % P;
	}
	return ans;
}

int modInverse(int a) {
	return power(a, P - 2);
}

void runTests() {
	int n, r; cin >> n >> r;

	vector<int> fact(n + 1, 1);

	for(int i = 2; i < n + 1; i++) {
		fact[i] = fact[i - 1] * i % P;
	}

	//nCr = n! / ((n - r)! * r!)

	int ncrmodp = fact[n] * modInverse(fact[n - r]) % P * modInverse(fact[r]) % P;

	cout << ncrmodp << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
