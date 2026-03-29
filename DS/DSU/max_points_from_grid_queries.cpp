class DSU {
private:
    int N;
    vector<int> parent, size;

public:
    DSU(int total) : N(total), parent(total, -1), size(total, 0) {}

    void makeSet(int x) {
        parent[x] = x;
        size[x] = 1;
    }

    int findSet(int x) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x]); // path compression
        }
        return parent[x];
    }

    void unionSet(int a, int b) {
        int pa = findSet(a);
        int pb = findSet(b);
        if (pa == pb) return;

        // union by size
        if (size[pa] < size[pb]) swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];
    }

    int getSize(int x) {
        if (parent[x] == -1) return 0;
        return size[findSet(x)];
    }

    bool isActive(int x) {
        return parent[x] != -1;
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        vector<array<int,3>> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back({grid[i][j], i, j});
            }
        }

        sort(v.begin(), v.end());

        DSU dsu(m * n);
        vector<int> dp;

        vector<int> dir = {-1, 0, 1, 0, -1};

        for (auto &ent : v) {
            int val = ent[0], r = ent[1], c = ent[2];
            int id = r * n + c;

            dsu.makeSet(id);

            // union with active neighbors
            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k];
                int nc = c + dir[k+1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int nid = nr * n + nc;
                if (dsu.isActive(nid)) {
                    dsu.unionSet(id, nid);
                }
            }

            // track answer for (0,0)
            int start = 0; // (0,0) → id = 0
            dp.push_back(dsu.getSize(start));
        }

        // answer queries via binary search
        vector<int> ans;
        for (int q : queries) {
            int l = 0, r = v.size() - 1;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (v[mid][0] >= q) r = mid - 1;
                else l = mid + 1;
            }

            ans.push_back(r >= 0 ? dp[r] : 0);
        }

        return ans;
    }
};
