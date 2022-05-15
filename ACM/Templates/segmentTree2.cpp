#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, lazy, ls, rs;
};

// query for the range sum
class segmentTree {
    int cnt;
    vector<Node> tr;

    void pushUp(int o, int l, int r) {
        tr[o].val = tr[tr[o].ls].val + tr[tr[o].rs].val;
    }

    void pushDown(int o, int l, int r) {
        if (!tr[o].ls) tr[o].ls = ++cnt, tr.push_back(Node());
        if (!tr[o].rs) tr[o].rs = ++cnt, tr.push_back(Node());
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

    int query(int o, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return tr[o].val;
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        return query(tr[o].ls, l, mid, ql, qr) +
               query(tr[o].rs, mid + 1, r, ql, qr);
    }

    void update(int o, int l, int r, int ql, int qr, int k) {
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            tr[o].lazy += k;
            tr[o].val += k * (r - l + 1);
            return;
        }
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        update(tr[o].ls, l, mid, ql, qr, k);
        update(tr[o].rs, mid + 1, r, ql, qr, k);
        pushUp(o, l, r);
    }
};