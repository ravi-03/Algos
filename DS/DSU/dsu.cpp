/*

	https://cp-algorithms.com/data_structures/disjoint_set_union.html

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

//DSU
vector<int> leader;
vector<int> rankk; //by depth of tree

void make_set(int a) {
	leader[a] = a;
	rankk[a] = 0;
}

int find_set(int a) {
	if(a == leader[a]) {
		return a;
	}
	return leader[a] = find_set(leader[a]); //path compression optimization
}

void union_set(int a, int b) {
	int leader_a = find_set(a);
	int leader_b = find_set(b);
	if(a != b) {
		if(rankk[leader_a] < rankk[leader_b]) { //union by rank optimization
			swap(leader_a, leader_b);
		}
		leader[leader_b] = leader_a;
		if(rankk[leader_a] == rankk[leader_b]) {
			rankk[leader_a]++;
		}
	}
}

void runTests() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	leader.clear(); leader.resize(n, -1);
	rankk.clear(); rankk.resize(n, -1);

	//make each index a set
	for(int i = 0; i < n; i++) {
		make_set(i);
	}

	int q; cin >> q;
	while(q--) {
		int type; cin >> type;
		//type == 1, find_set(a) : find leader of set containing a
		//type == 2, union_set(a, b) : merge sets containing a & b
		if(type == 1) {
			int a; cin >> a; //this is index not actual element of v;
			int leader = find_set(a);
			cout << "Leader of the set is : " << v[leader] << '\n';
		} else {
			int a, b; cin >> a >> b; //these are indexes not actual element of v;
			union_set(a, b);
			cout << "Merge successful\n";
		}
	}

	for(int i = 0; i < n; i++) {
		cout << leader[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i < n; i++) {
		cout << rankk[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
