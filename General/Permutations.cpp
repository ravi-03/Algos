#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> permutations;
vector<int> tmp;
vector<bool> visited;

void generatePermutations(vector<int> &v) {
	if(tmp.size() == v.size()) {
		permutations.push_back(tmp);
	} else {
		for(int i = 0; i < v.size(); i++) {
			if(!visited[i]) {
				//take this
				tmp.push_back(v[i]);
				visited[i] = true;
				generatePermutations(v);
				visited[i] = false;
				tmp.pop_back();
			}
		}
	}
}

void runTests() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	visited.resize(n, false);

	generatePermutations(v);

	for(auto vv : permutations) {
		for(int x : vv) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	cout << permutations.size() << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
