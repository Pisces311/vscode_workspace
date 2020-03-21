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

//查询动态区间第k小
int Kth_query(int pre, int cur, int l, int r, int k) {
    if (l >= r) return l;
    int x = t[t[cur].l].val - t[t[pre].l].val;
    int mid = (l + r) >> 1;
    if (x >= k)
        return Kth_query(t[pre].l, t[cur].l, l, mid, k);
    else
        return Kth_query(t[pre].r, t[cur].r, mid + 1, r, k - x);
}

//查询动态区间[l, r]之间数的个数
int num_query(int u, int v, int l, int r, int ql, int qr) {
    if (b[r] < ql || b[l] > qr) return 0;
    int x = t[v].val - t[u].val;
    if (ql <= b[l] && b[r] <= qr) return x;
    int mid = (l + r) >> 1;
    return num_query(t[u].l, t[v].l, l, mid, ql, qr) +
           num_query(t[u].r, t[v].r, mid + 1, r, ql, qr);
}

int main() {
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
    while (q--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int t = Kth_query(T[x - 1], T[y], 1, m, z);
        printf("%d\n", b[t]);
    }
    return 0;
}