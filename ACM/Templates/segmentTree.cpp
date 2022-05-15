#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class segmentTree {
    vector<T> val, lazy;

    int lc(int o) { return 2 * o + 1; }
    int rc(int o) { return 2 * o + 2; }

    void build(int o, vector<T>& a, int l, int r) {
        if (l == r) {
            val[o] = a[l];
        } else {
            int mid = (l + r) >> 1;
            build(lc(o), a, l, mid);
            build(rc(o), a, mid + 1, r);
            pushUp(o, l, r);
        }
    }

    void pushUp(int o, int l, int r) { val[o] = val[lc(o)] + val[rc(o)]; }

    void pushDown(int o, int l, int r) {
        if (lazy[o] != 0) {
            int mid = (l + r) / 2;
            val[lc(o)] += lazy[o] * (mid - l + 1);
            val[rc(o)] += lazy[o] * (r - mid);
            lazy[lc(o)] += lazy[o];
            lazy[rc(o)] += lazy[o];
            lazy[o] = 0;
        }
    }

   public:
    segmentTree(int n)
        : val(vector<T>((n + 5) << 2)), lazy(vector<T>((n + 5) << 2)) {}

    // 0-based
    segmentTree(vector<T>& a)
        : val(vector<T>((a.size() + 5) << 2)),
          lazy(vector<T>((a.size() + 5) << 2)) {
        build(0, a, 0, a.size() - 1);
    }

    T query(int o, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return val[o];
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        return (query(lc(o), l, mid, ql, qr) +
                query(rc(o), mid + 1, r, ql, qr));
    }

    void update(int o, int l, int r, int ql, int qr, T k) {
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            lazy[o] += k;
            val[o] += k * (r - l + 1);
            return;
        }
        pushDown(o, l, r);
        int mid = (l + r) >> 1;
        update(lc(o), l, mid, ql, qr, k);
        update(rc(o), mid + 1, r, ql, qr, k);
        pushUp(o, l, r);
    }
};