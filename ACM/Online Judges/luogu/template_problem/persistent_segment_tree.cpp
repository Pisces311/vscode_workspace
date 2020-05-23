#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int l, r, val;
} t[maxn << 5];

int n, q, m, cnt = 0;
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

int query(int u, int v, int l, int r, int k) {
    if (l >= r) return l;
    int x = t[t[v].l].val - t[t[u].l].val;
    int mid = (l + r) >> 1;
    if (x >= k)
        return query(t[u].l, t[v].l, l, mid, k);
    else
        return query(t[u].r, t[v].r, mid + 1, r, k - x);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    T[0] = build(1, m);
    for (int i = 1; i <= n; i++) {
        int t = lower_bound(b + 1, b + m + 1, a[i]) - b;
        T[i] = update(T[i - 1], 1, m, t);
    }
    while (q--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int t = query(T[x - 1], T[y], 1, m, z);
        printf("%d\n", b[t]);
    }

    return 0;
}