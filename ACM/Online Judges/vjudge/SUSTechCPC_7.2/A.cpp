#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m;
ll fib[75];

inline void init() {
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 70; ++i) fib[i] = fib[i - 1] + fib[i - 2];
}

ll find(ll x) {
    if (x <= 0) return fib[1];
    int p = lower_bound(fib + 1, fib + 71, x) - fib;
    if (abs(fib[p] - x) < abs(fib[p - 1] - x))
        return fib[p];
    else
        return fib[p - 1];
}

struct SegTreeNode {
    ll val, fib;
    bool lazy;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = t[o << 1].val + t[o << 1 | 1].val;
    t[o].fib = t[o << 1].fib + t[o << 1 | 1].fib;
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy) {
        t[o << 1].lazy = t[o].lazy;
        t[o << 1 | 1].lazy = t[o].lazy;
        t[o << 1].val = t[o << 1].fib;
        t[o << 1 | 1].val = t[o << 1 | 1].fib;
        t[o].lazy = false;
    }
}

void build(int o, int l, int r) {
    t[o].lazy = false;
    if (l == r) {
        t[o].val = 0;
        t[o].fib = find(t[o].val);
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o, l, r);
    }
}

ll query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].val += val;
        t[o].fib = find(t[o].val);
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

void update3(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy = true;
        t[o].val = t[o].fib;
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update3(o << 1, l, mid, ul, ur);
    update3(o << 1 | 1, mid + 1, r, ul, ur);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    while (cin >> n >> m) {
        build(1, 1, n);
        while (m--) {
            int op;
            cin >> op;
            if (op == 1) {
                int k, d;
                cin >> k >> d;
                update(1, 1, n, k, d);
            } else if (op == 2) {
                int l, r;
                cin >> l >> r;
                cout << query(1, 1, n, l, r) << '\n';
            } else {
                int l, r;
                cin >> l >> r;
                update3(1, 1, n, l, r);
            }
        }
    }

    return 0;
}