#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

int power(int x, int y) {

	if(y == 0) return 1;

	int tmp = power(x, y / 2);

	if(y & 1) {
		return x * tmp * tmp;
	} else {
		return tmp * tmp;
	}
}

double powerNegExp(double x, int y) {
	double tmp;
	if(y == 0) return 1;

	tmp = powerNegExp(x, y / 2);

	if(y % 2 == 0) {
		return tmp * tmp;
	} else {
		if(y < 0) {
			return (tmp * tmp) / x;
		} else {
			return tmp * tmp * x;
		}
	}
}

void runTests() {
	int x, y; cin >> x >> y;

	cout << power(x, y) << '\n';

	double xx; cin >> xx;
	int yy; cin >> yy;

	double powAns = powerNegExp(abs(xx), yy);

	if(xx < 0 && abs(yy) % 2 != 0) {
		powAns *= -1;
	}

	cout << powAns << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
