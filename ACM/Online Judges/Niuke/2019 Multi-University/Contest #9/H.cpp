#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct SegTreeNode {
    int l, r;
    double num, sum;
} t[maxn << 5];

int n, m, cnt = 0;
int a[maxn], T[maxn];
double pre[maxn];

int build(int l, int r) {
    int o = ++cnt;
    t[o].num = t[o].sum = 0;
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
    t[o].num = t[pre].num + 1;
    t[o].sum = t[pre].sum + x;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (x <= mid)
            t[o].l = update(t[pre].l, l, mid, x);
        else
            t[o].r = update(t[pre].r, mid + 1, r, x);
    }
    return o;
}

double query(int u, int v, int l, int r, double p) {
    if (!u && !v) return 0;
    if (p > r) return 0;
    if (p <= l) return (t[u].sum - t[v].sum) - (t[u].num - t[v].num) * p;
    int mid = (l + r) >> 1;
    return query(t[u].l, t[v].l, l, mid, p) +
           query(t[u].r, t[v].r, mid + 1, r, p);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    T[0] = build(1, 100000);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        T[i] = update(T[i - 1], 1, 100000, a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    while (m--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        double _l = 0, _r = 100000, mid;
        for (int stp = 0; stp < 50; stp++) {
            mid = (_l + _r) * 0.5;
            if (query(T[r], T[l - 1], 1, 100000, mid) >=
                1.0 * x / y * (pre[r] - pre[l - 1]))
                _l = mid;
            else
                _r = mid;
        }
        cout << setiosflags(ios::fixed) << setprecision(15) << (_l + _r) * 0.5
             << '\n';
    }

    return 0;
}