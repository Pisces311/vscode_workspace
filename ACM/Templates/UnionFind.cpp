#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, size;

   public:
    UnionFind(int n) : parent(vector<int>(n)), size(vector<int>(n, 1)) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (size[pu] > size[pv]) {  // Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};