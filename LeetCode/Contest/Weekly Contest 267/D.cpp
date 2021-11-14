#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;

   public:
    UnionFind(int n) : parent(vector<int>(n)) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    void Union(int u, int v) { parent[u] = v; }
};

class Solution {
    void join(set<int>& a, set<int>& b) {
        for (int i : b) a.insert(i);
    }

   public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        vector<set<int>> enemies(n);
        for (auto res : restrictions) {
            int u = res[0], v = res[1];
            enemies[u].insert(v);
            enemies[v].insert(u);
        }
        UnionFind uf(n);
        vector<bool> ans(requests.size());
        for (int i = 0; i < requests.size(); i++) {
            int u = requests[i][0], v = requests[i][1];
            int pu = uf.find(u), pv = uf.find(v);
            auto check = [&](int x, int y) {
                for (int enemy : enemies[x]) {
                    if (uf.find(enemy) == y) return false;
                }
                for (int enemy : enemies[y]) {
                    if (uf.find(enemy) == x) return false;
                }
                return true;
            };
            if (check(pu, pv)) {
                ans[i] = true;
                uf.Union(pu, pv);
                join(enemies[pv], enemies[pu]);
            }
        }
        return ans;
    }
};