#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int N, M;
int a[maxn];

struct SegTreeNode {
    int val;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

void build(int o, int arr[], int l, int r) {
    if (l == r) {
        t[o].val = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    int mid = (l + r) >> 1;
    return max(query(o << 1, l, mid, ql, qr),
               query(o << 1 | 1, mid + 1, r, ql, qr));
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        for (int i = 1; i <= N; ++i) cin >> a[i];
        build(1, a, 1, N);
        while (M--) {
            char opt;
            int u, v;
            cin >> opt >> u >> v;
            if (opt == 'U')
                update(1, 1, N, u, v);
            else
                cout << query(1, 1, N, u, v) << '\n';
        }
    }

    return 0;
}