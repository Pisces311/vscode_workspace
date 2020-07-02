#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
constexpr int maxn = 1e5 + 5;

int T, n, m;
uint W, X, Y, Z;

uint RNG61() {
    X = X ^ (X << 11);
    X = X ^ (X >> 4);
    X = X ^ (X << 5);
    X = X ^ (X >> 14);
    W = X ^ (Y ^ Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}

struct SegTreeNode {
    ll min, max, lazy;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].min = min(t[o << 1].min, t[o << 1 | 1].min);
    t[o].max = max(t[o << 1].max, t[o << 1 | 1].max);
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy) {
        int lazy = t[o].lazy;
        t[o << 1] = {lazy, lazy, lazy};
        t[o << 1 | 1] = {lazy, lazy, lazy};
        t[o].lazy = 0;
    }
}

void build(int o, int l, int r) {
    t[o].lazy = 0;
    if (l == r) {
        t[o].min = t[o].max = 0;
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o, l, r);
    }
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (t[o].min >= val) return;
    if (ul <= l && r <= ur) {
        if (t[o].max < val) {
            t[o].lazy = val;
            t[o].min = t[o].max = val;
            return;
        }
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

ll query(int o, int l, int r, int p) {
    if (r < p || p < l) return 0;
    if (p <= l && r <= p) return t[o].max;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return query(o << 1, l, mid, p) + query(o << 1 | 1, mid + 1, r, p);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m >> X >> Y >> Z;
        build(1, 1, n);
        while (m--) {
            int l = RNG61() % n + 1, r = RNG61() % n + 1,
                v = RNG61() % (1 << 30);
            if (l > r) swap(l, r);
            update(1, 1, n, l, r, v);
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) ans ^= i * query(1, 1, n, i);
        cout << ans << '\n';
    }

    return 0;
}