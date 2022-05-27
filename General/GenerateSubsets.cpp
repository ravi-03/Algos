#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

vector<vector<int>> subsets;
vector<int> tmp;

void generateSubsets(vector<int> &v, int ind) {
	if(ind == v.size()) {
		subsets.push_back(tmp);
	} else {
		//take this element
		tmp.push_back(v[ind]);
		generateSubsets(v, ind + 1);
		//don't take this element
		tmp.pop_back();
		generateSubsets(v, ind + 1);

		// generateSubsets(v, ind + 1);
		// tmp.push_back(v[ind]);
		// generateSubsets(v, ind + 1);
		// tmp.pop_back();
	}
}

void runTests() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	generateSubsets(v, 0);

	for(auto vv : subsets) {
		for(int x : vv) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	cout << subsets.size() << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
