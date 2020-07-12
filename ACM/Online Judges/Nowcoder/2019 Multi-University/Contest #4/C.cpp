#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e6 + 10;

struct node {
    int l, r;
    ll maxx, minn;
} t[maxn << 2];

int n;
int l[maxn], r[maxn];
int a[maxn], b[maxn];
ll sum[maxn];

void pushup(int o) {
    t[o].maxx = max(t[o << 1].maxx, t[o << 1 | 1].maxx);
    t[o].minn = min(t[o << 1].minn, t[o << 1 | 1].minn);
}

void build(int l, int r, int o) {
    t[o].l = l;
    t[o].r = r;
    if (l == r) {
        t[o].maxx = t[o].minn = sum[l];
        return;
    }
    int mid = (r + l) >> 1;
    build(l, mid, o << 1);
    build(mid + 1, r, o << 1 | 1);
    pushup(o);
}

ll querymax(int pl, int pr, int o) {
    if (pl <= t[o].l && t[o].r <= pr) {
        return t[o].maxx;
    }
    ll res = -1e18;
    if (pl <= t[o << 1].r) res = max(res, querymax(pl, pr, o << 1));
    if (pr >= t[o << 1 | 1].l) res = max(res, querymax(pl, pr, o << 1 | 1));
    return res;
}

ll querymin(int pl, int pr, int o) {
    if (pl <= t[o].l && t[o].r <= pr) {
        return t[o].minn;
    }
    ll res = 1e18;
    if (pl <= t[o << 1].r) res = min(res, querymin(pl, pr, o << 1));
    if (pr >= t[o << 1 | 1].l) res = min(res, querymin(pl, pr, o << 1 | 1));

    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        sum[i] = sum[i - 1] + b[i];
    }
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty())
            l[i] = 0;
        else {
            l[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty())
            r[i] = n;
        else
            r[i] = s.top() - 1;
        s.push(i);
    }
    build(0, n, 1);
    ll ans = -1e18, cnt;
    for (int i = 1; i <= n; i++) {
        cnt = a[i];
        if (cnt > 0)
            cnt = cnt * (querymax(i, r[i], 1) - querymin(l[i], i - 1, 1));
        else
            cnt = cnt * (querymin(i, r[i], 1) - querymax(l[i], i - 1, 1));
        ans = max(ans, cnt);
    }
    printf("%lld\n", ans);

    return 0;
}