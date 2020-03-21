#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;
const int mod = 1e9 + 7;

int n, m;

struct SegTreeNode {
    ll mat[3][3];
    void init() {
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 2; ++j) mat[i][j] = 1;
    }
    ll sum() {
        return ((mat[1][1] + mat[1][2]) % mod + (mat[2][1] + mat[2][2]) % mod) %
               mod;
    }
} I, t[maxn << 2];

SegTreeNode mul(const SegTreeNode& a, const SegTreeNode& b) {
    SegTreeNode ans;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            ans.mat[i][j] = 0;
            for (int k = 1; k <= 2; ++k) {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}

void pushUp(int o, int l, int r) { t[o] = mul(t[o << 1], t[o << 1 | 1]); }

void build(int o, int l, int r) {
    if (l == r) {
        t[o].init();
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o, l, r);
    }
}

SegTreeNode query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return I;
    if (ql <= l && r <= qr) return t[o];
    int mid = (l + r) >> 1;
    return mul(query(o << 1, l, mid, ql, qr),
               query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int p, int y, int z) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].mat[y][z] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, y, z);
    update(o << 1 | 1, mid + 1, r, p, y, z);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    I.mat[1][1] = I.mat[2][2] = 1;
    while (cin >> n >> m) {
        build(1, 1, n);
        while (m--) {
            int opt, x, y, z;
            cin >> opt;
            if (opt == 1) {
                cin >> x >> y >> z;
                update(1, 1, n, x, y, z);
            } else {
                cin >> x >> y;
                cout << query(1, 1, n, x, y - 1).sum() << '\n';
            }
        }
    }

    return 0;
}