/*
	https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int maxn = 1e6 + 1;

vector<bool> isPrime(maxn, true);
vector<int> SPF(maxn);
vector<int> primes;

void mod_seive() {
	isPrime[0] = isPrime[1] = false;
	for(int cur_ele = 2; cur_ele < maxn; cur_ele++) {
		if(isPrime[cur_ele]) {
			primes.push_back(cur_ele);
			SPF[cur_ele] = cur_ele;
		}
		for(int j = 0; j < (int)primes.size() && cur_ele * primes[j] < maxn 
			&& primes[j] <= SPF[cur_ele]; j++) {
			isPrime[cur_ele * primes[j]] = false;
			SPF[cur_ele * primes[j]] = primes[j];
		}
	}
}

vector<int> primeFactor(int x) {
	assert(x >= 2 && x < maxn);
	vector<int> factors;
	int i;
	for(i = x; i != SPF[i]; i /= SPF[i]) {
		factors.push_back(SPF[i]);
	}
	factors.push_back(i);
	return factors;
}

void runTests() {
	int n; cin >> n;
	cout << "primes before " << n << " are : ";
	for(int x : primes) {
		if(x > n) break;
		cout << x << ' ';
	}
	cout << '\n';
	cout << "Prime factorization of " << n << " is : ";
	vector<int> factors = primeFactor(n);
	for(int x : factors) {
		cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	mod_seive();
	while(t--) runTests();
	return 0;
}
