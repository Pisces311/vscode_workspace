#include <bits/stdc++.h>
using namespace std;

// query for the range sum
template <typename T = int, int mn = 0, int mx = 100000>
class segmentTree {
    struct Node {
        T val, lazy;
        int ls, rs;
    };

    int cnt;
    vector<Node> tr;

    void pushUp(int o, int l, int r) {
        tr[o].val = tr[tr[o].ls].val + tr[tr[o].rs].val;
    }

    void pushDown(int o, int l, int r) {
        if (!tr[o].ls) tr[o].ls = ++cnt, tr.emplace_back();
        if (!tr[o].rs) tr[o].rs = ++cnt, tr.emplace_back();
        if (tr[o].lazy != 0) {
            int mid = (l + r) / 2;
            tr[tr[o].ls].val += tr[o].lazy * (mid - l + 1);
            tr[tr[o].rs].val += tr[o].lazy * (r - mid);
            tr[tr[o].ls].lazy += tr[o].lazy;
            tr[tr[o].rs].lazy += tr[o].lazy;
            tr[o].lazy = 0;
        }
    }

   public:
    segmentTree() : tr(1), cnt(0) { tr.reserve(500000); }

    T query(int ql, int qr, int o = 0, int l = mn, int r = mx) {
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return tr[o].val;
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        return query(ql, qr, tr[o].ls, l, mid) +
               query(ql, qr, tr[o].rs, mid + 1, r);
    }

    void update(int ql, int qr, T k, int o = 0, int l = mn, int r = mx) {
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            tr[o].lazy += k;
            tr[o].val += k * (r - l + 1);
            return;
        }
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        update(ql, qr, k, tr[o].ls, l, mid);
        update(ql, qr, k, tr[o].rs, mid + 1, r);
        pushUp(o, l, r);
    }
};