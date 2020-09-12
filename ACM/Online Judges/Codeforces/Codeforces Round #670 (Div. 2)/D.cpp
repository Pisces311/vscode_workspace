#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, q;
ll add = 0, sub = 0;
ll a[maxn];

struct SegTreeNode {
    ll val, lazy;
} t[maxn << 2];

void pushDown(int o, int l, int r) {
    if (t[o].lazy != 0) {
        t[o << 1].lazy += t[o].lazy;
        t[o << 1 | 1].lazy += t[o].lazy;
        t[o << 1].val += t[o].lazy;
        t[o << 1 | 1].val += t[o].lazy;
        t[o].lazy = 0;
    }
}

void build(int o, ll arr[], int l, int r) {
    t[o].lazy = 0;
    if (l == r) {
        t[o].val = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
    }
}

ll query(int o, int l, int r, int q) {
    if (r < q || q < l) return 0;
    if (q <= l && r <= q) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, q) + query(o << 1 | 1, mid + 1, r, q));
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy += val;
        t[o].val += val * (r - l + 1);
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
}

ll get(ll add, ll sub) {
    ll base = query(1, 1, n, 1);
    if ((base - max(add, sub)) % 2 == 0) {
        ll y = (base - max(add, sub)) / 2;
        ll x = base - y;
        return x;
    } else {
        if (add > sub) {
            add -= 1;
            ll y = (base - add) / 2;
            ll x = base - y;
            return x + 1;
        } else {
            ll y = (base - sub - 1) / 2;
            ll x = base - y;
            return x;
        }
    }
}

void cal(ll x, ll y, ll flag) {
    if (x > y)
        add += flag * (x - y);
    else
        sub += flag * (y - x);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, a, 1, n);
    for (int i = 2; i < n; ++i) cal(a[i], a[i - 1], 1);
    sub += a[n] - a[1];
    cout << get(add, sub) << '\n';
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        if (l != 1) cal(query(1, 1, n, l), query(1, 1, n, l - 1), -1);
        if (r != n) cal(query(1, 1, n, r + 1), query(1, 1, n, r), -1);
        if (l == 1 || r == n) sub -= query(1, 1, n, n) - query(1, 1, n, 1);
        update(1, 1, n, l, r, x);
        if (l != 1) cal(query(1, 1, n, l), query(1, 1, n, l - 1), 1);
        if (r != n) cal(query(1, 1, n, r + 1), query(1, 1, n, r), 1);
        if (l == 1 || r == n) sub += query(1, 1, n, n) - query(1, 1, n, 1);
        cout << get(add, sub) << '\n';
    }

    return 0;
}