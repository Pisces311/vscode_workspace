#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct SegTreeNode {
    int l, r, val;
} t[maxn << 5];

int cas, n, m, q, cnt;
int a[maxn], b[maxn], T[maxn];

int build(int l, int r) {
    int o = ++cnt;
    t[o].val = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        t[o].l = build(l, mid);
        t[o].r = build(mid + 1, r);
    }
    return o;
}

int update(int pre, int l, int r, int x) {
    int o = ++cnt;
    t[o].l = t[pre].l;
    t[o].r = t[pre].r;
    t[o].val = t[pre].val + 1;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (x <= mid)
            t[o].l = update(t[pre].l, l, mid, x);
        else
            t[o].r = update(t[pre].r, mid + 1, r, x);
    }
    return o;
}

int query(int u, int v, int l, int r, int ql, int qr) {
    if (b[r] < ql || b[l] > qr) return 0;
    int x = t[v].val - t[u].val;
    if (ql <= b[l] && b[r] <= qr) return x;
    int mid = (l + r) >> 1;
    return query(t[u].l, t[v].l, l, mid, ql, qr) +
           query(t[u].r, t[v].r, mid + 1, r, ql, qr);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &cas);
    while (cas--) {
        cnt = 0;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        m = unique(b + 1, b + n + 1) - b - 1;
        T[0] = build(1, m);
        for (int i = 1; i <= n; ++i) {
            int t = lower_bound(b + 1, b + m + 1, a[i]) - b;
            T[i] = update(T[i - 1], 1, m, t);
        }
        int X = 0;
        while (q--) {
            int l, r, p, k;
            scanf("%d %d %d %d", &l, &r, &p, &k);
            l ^= X, r ^= X, p ^= X, k ^= X;
            int _l = 0, _r = 1000000, mid;
            while (_l <= _r) {
                mid = (_l + _r) >> 1;
                int num = query(T[l - 1], T[r], 1, m, p - mid, p + mid);
                if (num < k) {
                    _l = mid + 1;
                } else if (num >= k) {
                    _r = mid - 1;
                    X = mid;
                }
            }
            printf("%d\n", X);
        }
    }

    return 0;
}