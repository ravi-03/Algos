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
#include "../debug.h"
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

vector<int> findPrefix(string s) {
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

vector<int> kmp(string pattern, string text) {
	string s = pattern + "#" + text;
	vector<int> pi = findPrefix(s);
	int n = pattern.size();
	vector<int> occurences;
	for (int i = n + 1; i < (int)s.size(); i++) {
		if (pi[i] == n) {
			occurences.push_back(i - 2 * n);
		}
	}
	return occurences;
}

void runTests() {
	string s = "abcabcd";
	// string s = "aaaaa";
	debug(findPrefix(s));
	// string t = "aa";
	string t = "abc";
	debug(kmp(t, s));
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1; 
	while(t--) runTests();
	return 0;
}

