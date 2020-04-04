#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3.5e4 + 5;

struct SegTreeNode {
    int val, lazy;
} t[maxn << 2];

int n, k;
int dp[60][40000], pre[maxn], pos[maxn];

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy != 0) {
        t[o << 1].lazy += t[o].lazy;
        t[o << 1 | 1].lazy += t[o].lazy;
        t[o << 1].val += t[o].lazy;
        t[o << 1 | 1].val += t[o].lazy;
        t[o].lazy = 0;
    }
}

void build(int o, int l, int r, int cur) {
    t[o].lazy = 0;
    if (l == r) {
        t[o].val = dp[cur][l - 1];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid, cur);
        build(o << 1 | 1, mid + 1, r, cur);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return max(query(o << 1, l, mid, ql, qr),
               query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy += val;
        t[o].val += val;
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        pre[i] = pos[x] + 1;
        pos[x] = i;
    }
    for (int i = 1; i <= k; i++) {
        memset(t, 0, sizeof(t));
        build(1, 1, n, i - 1);
        for (int j = 1; j <= n; j++) {
            update(1, 1, n, pre[j], j, 1);
            dp[i][j] = query(1, 1, n, 1, j);
        }
    }
    cout << dp[k][n] << '\n';

    return 0;
}