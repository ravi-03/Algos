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

// find all primes <= n.
vector<int> sieve(int n) {
	/*
	TC: O(n * log(log(n))) => because it's harmonic sum over primes.
	SC: O(n)

	n * (1/1 + 1/2 + 1/3 ... 1/n) = n * log(n)
	n * (1/2 + 1/3 + 1/5 + 1/7 ... ) = n * log(log(n))
	*/
	vector<bool> prime(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			// mark all multiples starting from i * i as not prime. Smaller 
			// multiples are covered by smaller primes.
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	vector<int> primes;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);
		}
	}
	return primes;
}

void runTests() {
	int n = 100;
	vector<int> primes = sieve(100);
	for (int x: primes) {
		cout << x << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1; 
	while(t--) runTests();
	return 0;
}
