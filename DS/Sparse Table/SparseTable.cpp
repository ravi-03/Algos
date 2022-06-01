/*
	https://cp-algorithms.com/data_structures/sparse-table.html#range-minimum-queries-rmq
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

//sparse table
vector<vector<int>> sparseTable; //sparseTable[start][length_pow]
int K;

void buildSparseTable(vector<int> &a) {
	int n = a.size();

	K = log2(n);
	sparseTable.clear();
	sparseTable.resize(n, vector<int>(K + 1));

	for(int row = 0; row < n; row++) {
		sparseTable[row][0] = a[row]; //Check1
	}

	for(int len_pow = 1; len_pow <= K; len_pow++) {
		for(int row = 0; row + (1 << len_pow) <= n; row++) {
			sparseTable[row][len_pow] = sparseTable[row][len_pow - 1] 
				+ sparseTable[row + (1 << len_pow - 1)][len_pow - 1]; //Check2
		}
	}
}

int sparseTableQuery(int &L, int &R) {
	int sum = 0; //Check3
	for(int len_pow = K; len_pow >= 0; len_pow--) {
		if((1 << len_pow) <= R - L + 1) {
			sum += sparseTable[L][len_pow]; //Check4
			L += (1 << len_pow);
		}
	}
	return sum;
}

void runTests() {

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	buildSparseTable(a);

	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		cout << sparseTableQuery(l, r) << '\n';
	}

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
