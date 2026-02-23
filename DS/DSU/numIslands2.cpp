class DSU {
private:
    int n;
    int m;
    vector<vector<pair<int,int>>> leader;
    vector<vector<int>> rank;
    int islands;

public:
    DSU(int n, int m) : n(n), m(m) {
        leader.assign(n, vector<pair<int,int>>(m, {-1, -1}));
        rank.assign(n, vector<int>(m, 0));
        islands = 0;
    }

    void makeSet(pair<int,int> p) {
        if (leader[p.first][p.second] != std::make_pair(-1, -1)) {
            return;
        }
        leader[p.first][p.second] = p;
        rank[p.first][p.second] = 0;
        islands++;
    }

    pair<int,int> findSet(pair<int,int> p) {
        // returns leader of the set to which p belongs.
        auto &par = leader[p.first][p.second];
        if (par == p) return p;
        return par = findSet(par);
    }

    void unionSets(pair<int,int> p1, pair<int,int> p2) {
        // combine two sets corresponding to p1 & p2.
        pair<int,int> l1 = findSet(p1);
        pair<int,int> l2 = findSet(p2);
        if (l1 == l2) return;
        islands--;
        if (rank[l1.first][l1.second] < rank[l2.first][l2.second]) {
            swap(l1, l2);
        }
        leader[l2.first][l2.second] = l1;
        if (rank[l1.first][l1.second] == rank[l2.first][l2.second]) {
            rank[l1.first][l1.second]++;
        }
    }

    int getIslands() {
        return islands;
    }
};

class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> land;

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        land.resize(m, vector<bool>(n, false));
        DSU dsu = DSU(m, n);
        vector<int> ans;
        for (auto pos : positions) {
            dsu.makeSet({pos[0], pos[1]});
            if (land[pos[0]][pos[1]]) {
                ans.push_back(dsu.getIslands());
                continue;
            }
            land[pos[0]][pos[1]] = true;
            for (auto d: dir) {
                int i = pos[0] + d[0];
                int j = pos[1] + d[1];
                if (i < 0 || i >= m || j < 0 || j >= n || !land[i][j]) continue;
                dsu.unionSets({pos[0], pos[1]}, {i, j});
            }
            ans.push_back(dsu.getIslands());
        }
        return ans;
    }
};
