#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

int nCr(int n, int r) {
	if(r > n - r) 
		r = n - r;
	int nume = 1, deno = 1;
	while(r) {
		nume *= n;
		deno *= r;

		int g = __gcd(nume, deno);

		nume /= g;
		deno /= g;

	  	n--, r--;
	}
	return nume;
}

void runTests() {
	int n, r; cin >> n >> r;

	cout << nCr(n, r) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
