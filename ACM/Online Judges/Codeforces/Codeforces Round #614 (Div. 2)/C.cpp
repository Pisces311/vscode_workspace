#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, q;
int r[maxn], c[maxn];
int maze[3][maxn];

struct SegTreeNode {
    int val;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

void build(int o, int l, int r) {
    if (l == r) {
        t[o].val = 0;
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o, l, r);
    }
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].val = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

bool check(int col) {
    bool flag = false;
    if (maze[1][col] == 0 && maze[1][col + 1] == 0) flag = true;
    if (maze[2][col] == 0 && maze[2][col + 1] == 0) flag = true;
    return flag;
}

void solve(int col) {
    if (col != n) {
        if (check(col))
            update(1, 1, n, col, 0);
        else
            update(1, 1, n, col, 1);
    }
    if (col != 1) {
        if (check(col - 1))
            update(1, 1, n, col - 1, 0);
        else
            update(1, 1, n, col - 1, 1);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= q; ++i) cin >> r[i] >> c[i];
    for (int i = 1; i <= q; ++i) {
        maze[r[i]][c[i]] ^= 1;
        solve(c[i]);
        if (!t[1].val)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}