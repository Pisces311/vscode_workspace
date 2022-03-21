#include <bits/stdc++.h>
using namespace std;

class segmentTree {
   public:
    vector<char> lchar, rchar;
    vector<int> lmax, rmax, _max;

    // 0-based
    segmentTree(string& a)
        : lchar(vector<char>((a.size() + 5) << 2)),
          rchar(vector<char>((a.size() + 5) << 2)),
          lmax(vector<int>((a.size() + 5) << 2)),
          rmax(vector<int>((a.size() + 5) << 2)),
          _max(vector<int>((a.size() + 5) << 2)) {
        build(0, a, 0, a.size() - 1);
    }

    int lc(int o) { return 2 * o + 1; }
    int rc(int o) { return 2 * o + 2; }

    void build(int o, string& a, int l, int r) {
        if (l == r) {
            lchar[o] = rchar[o] = a[l];
            lmax[o] = rmax[o] = _max[o] = 1;
        } else {
            int mid = (l + r) >> 1;
            build(lc(o), a, l, mid);
            build(rc(o), a, mid + 1, r);
            pushUp(o, l, r);
        }
    }

    void pushUp(int o, int l, int r) {
        lchar[o] = lchar[lc(o)];
        rchar[o] = rchar[rc(o)];
        lmax[o] = lmax[lc(o)];
        rmax[o] = rmax[rc(o)];
        _max[o] = max(_max[lc(o)], _max[rc(o)]);
        int mid = (l + r) >> 1;
        if (rchar[lc(o)] == lchar[rc(o)]) {
            if (lmax[o] == mid - l + 1) lmax[o] += lmax[rc(o)];
            if (rmax[o] == r - (mid + 1) + 1) rmax[o] += rmax[lc(o)];
            _max[o] = max(_max[o], rmax[lc(o)] + lmax[rc(o)]);
        }
    }

    void update(int o, int l, int r, int q, char k) {
        if (r < q || q < l) return;
        if (q <= l && r <= q) {
            lchar[o] = rchar[o] = k;
            lmax[o] = rmax[o] = _max[o] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        update(lc(o), l, mid, q, k);
        update(rc(o), mid + 1, r, q, k);
        pushUp(o, l, r);
    }
};

class Solution {
   public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        segmentTree st(s);
        int n = s.size();
        int q = queryCharacters.size();
        vector<int> res(q);
        for (int i = 0; i < q; i++) {
            st.update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            res[i] = st._max[0];
        }
        return res;
    }
};