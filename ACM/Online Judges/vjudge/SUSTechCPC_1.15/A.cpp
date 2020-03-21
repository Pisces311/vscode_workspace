#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, M;
int a[maxn];

struct SegTreeNode {
    ll val;
    bool ok;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = t[o << 1].val + t[o << 1 | 1].val;
    t[o].ok = t[o << 1].ok && t[o << 1 | 1].ok;
}

void build(int o, int arr[], int l, int r) {
    t[o].ok = false;
    if (l == r) {
        t[o].val = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
        pushUp(o, l, r);
    }
}

ll query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        if (l == r) {
            t[o].val = sqrt(t[o].val);
            t[o].ok = (t[o].val == 1 || t[o].val == 0);
            return;
        } else {
            if (t[o].ok) return;
        }
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur);
    update(o << 1 | 1, mid + 1, r, ul, ur);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    build(1, a, 1, N);
    cin >> M;
    while (M--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            cout << query(1, 1, N, l, r) << '\n';
        } else {
            update(1, 1, N, l, r);
        }
    }

    return 0;
}