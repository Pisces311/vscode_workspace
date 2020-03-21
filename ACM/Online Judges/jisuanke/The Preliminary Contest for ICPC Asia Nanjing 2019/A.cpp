#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct palace {
    int x, y;
    ll val;
    bool operator<(const palace& a) const { return y < a.y; }
} a[maxn];

struct Edge {
    int l, r, y, f, id;
    bool operator<(const Edge& a) const { return y == a.y ? f > a.f : y < a.y; }
} edge[maxn];

int T, n, m, p, top;
ll pre[maxn], ans[maxn];

inline void init() { top = 0; }

ll cal(int n, int x, int y) {
    int c = (n + 1) / 2, l = max(abs(x - c), abs(y - c));
    ll ret, ans;
    if (x == c && y == c) ans = 1ll * n * n;
    ret = 1ll * n * n - pow(1ll * (2 * l + 1), 2ll) + 1;
    if ((y - c) == l && ((x - c) != l))
        ans = ret + (x - c + l) + (6 * l);
    else {
        if (c == l + x) ans = ret + y - c + 5 * l;
        if (c == l + y) ans = ret + c + 3 * l - x;
        if (c == -l + x) ans = ret + c + l - y;
    }
    ll cnt = 0;
    while (ans) {
        cnt += ans % 10;
        ans /= 10;
    }
    return cnt;
}

ll t[maxn << 2];

void pushUp(int o, int l, int r) { t[o] = t[o << 1] + t[o << 1 | 1]; }

ll query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o];
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int p, ll val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o] += val;
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

    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        init();
        for (int i = 1; i <= m; ++i) {
            cin >> a[i].x >> a[i].y;
            a[i].val = cal(n, a[i].x, a[i].y);
        }
        sort(a + 1, a + m + 1);
        for (int i = 1; i <= p; ++i) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            edge[++top] = {x1, x2, y1, 1, i};
            edge[++top] = {x1, x2, y2, -1, i};
        }
        sort(edge + 1, edge + top + 1);
        memset(t, 0, sizeof(t));
        for (int i = 1, j = 1; i <= top; ++i) {
            if (edge[i].f == 1) {
                while (edge[i].y > a[j].y && j <= m) {
                    update(1, 1, 1000000, a[j].x, a[j].val);
                    ++j;
                }
                pre[edge[i].id] = query(1, 1, 1000000, edge[i].l, edge[i].r);
            } else {
                while (edge[i].y >= a[j].y && j <= m) {
                    update(1, 1, 1000000, a[j].x, a[j].val);
                    ++j;
                }
                ans[edge[i].id] = query(1, 1, 1000000, edge[i].l, edge[i].r) -
                                  pre[edge[i].id];
            }
        }
        for (int i = 1; i <= p; ++i) cout << ans[i] << '\n';
    }

    return 0;
}