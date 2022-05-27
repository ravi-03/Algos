#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int P = 1e9 + 7;

/*

	x^7 = x^(2^2 + 2^1 + 2^0) = x^2^2 * x^2^1 * x^2^0

*/

ull powerModP(ull x, int y, int P) {
	ull ans = 1;
	x = x % P;
	while(y > 0) {
		if(y & 1) {
			ans = (ans * x) % P;
		}
		y = y >> 1; //y = y / 2
		x = (x * x) % P; //every term in last expression
	}
	return ans;
}

void runTests() {
	int x, y; cin >> x >> y;
	cout << powerModP(x, y, P) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
