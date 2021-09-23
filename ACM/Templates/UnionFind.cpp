#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, size;

   public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;           // Return False if u and v are already union
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