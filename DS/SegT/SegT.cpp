/*

	https://cp-algorithms.com/data_structures/segment_tree.html

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<int> a;
vector<int> st;

void buildST(int tv, int tl, int tr) {
	if(tl == tr) {
		st[tv] = a[tl];    //check1
	} else {
		int tm = (tl + tr) / 2;
		buildST(2 * tv + 1, tl, tm);
		buildST(2 * tv + 2, tm + 1, tr);
		st[tv] = st[2 * tv + 1] + st[2 * tv + 2];	//check2
	}
}

int queryST(int tv, int tl, int tr, int l, int r) {
	if(tl == l && tr == r) {
		return st[tv];
	} else {
		int tm = (tl + tr) / 2;
		if(r <= tm) { //left
			return queryST(2 * tv + 1, tl, tm, l, r);
		} else if(l > tm) { //right
			return queryST(2 * tv + 2, tm + 1, tr, l, r);
		} else { //both
			return queryST(2 * tv + 1, tl, tm, l, tm) +			//check3
					queryST(2 * tv + 2, tm + 1, tr, tm + 1, r);
		}
	}
}

void updateST(int tv, int tl, int tr, int ind, int val) {
	if(tl == tr && tl == ind) {
		st[tv] = val;	//check4
	} else {
		int tm = (tl + tr) / 2;
		if(ind <= tm) { //left
			updateST(2 * tv + 1, tl, tm, ind, val);
		} else { //right
			updateST(2 * tv + 2, tm + 1, tr, ind, val);
		}
		st[tv] = st[2 * tv + 1] + st[2 * tv + 2]; //check5
	}
}

void runTests() {
	int n; cin >> n;
	a.resize(n);
	st.resize(4 * n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	buildST(0, 0, n - 1);

	int q; cin >> q;
	while(q--) {
		int type; cin >> type;
		//type1 - query
		if(type == 1) {
			int l, r; cin >> l >> r;
<<<<<<< HEAD
			if(l > r) {
=======
			if(l > r || l < 0 || l >= n || r < 0 || r >= n) {
>>>>>>> f272b2c (Basic Segment Tree)
				cout << "Incorrect range\n";
				continue;
			}
			cout << queryST(0, 0, n - 1, l, r) << '\n';
		}
		//type2 - update
		else {
			int ind, val; cin >> ind >> val;
			if(ind < 0 || ind >= n) {
				cout << "Out of bound index\n";
				continue;
			}
			updateST(0, 0, n - 1, ind, val);
			cout << "Update successful\n";
		}
	}

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
