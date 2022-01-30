#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> parent, size;

    UnionFind(int n) : parent(vector<int>(n)), size(vector<int>(n, 1)) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        size[pu] += size[pv];
        parent[pv] = pu;
        return true;
    }
};

class Solution {
   public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> pos;
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            bitset<32> bits;
            for (char ch : words[i]) bits.set(ch - 'a');
            int num = bits.to_ulong();
            if (pos.count(num)) uf.Union(i, pos[num]);
            for (int j = 0; j < 26; j++) {
                bitset<32> tmp(bits);
                int ad = tmp.flip(j).to_ulong();
                if (pos.count(ad)) uf.Union(i, pos[ad]);
            }
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (bits.test(j) && !bits.test(k)) {
                        bitset<32> tmp(bits);
                        int ex = tmp.flip(j).flip(k).to_ulong();
                        if (pos.count(ex)) uf.Union(i, pos[ex]);
                    }
                }
            }
            pos[num] = i;
        }

        int cnt = 0, size = -1;
        for (int i = 0; i < n; i++) {
            if (uf.parent[i] == i) {
                cnt++;
                size = max(size, uf.size[i]);
            }
        }
        return {cnt, size};
    }
};