#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, i, x, y;
int tot, v[maxn], l[maxn], r[maxn], d[maxn], fa[maxn];

inline void init() {
    tot = 0;
    up(i, 1, n) fa[i] = i;
    mem(l, 0);
    mem(r, 0);
    mem(d, 0);
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    if (v[x] < v[y]) swap(x, y);
    r[x] = merge(r[x], y);
    fa[r[x]] = x;
    if (d[l[x]] < d[r[x]]) swap(l[x], r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}

int pop(int x) {
    int L = l[x], R = r[x];
    fa[L] = L;
    fa[R] = R;
    v[x] /= 2;
    r[x] = l[x] = d[x] = 0;
    return merge(L, R);
}

int top(int x) { return v[x]; }

void solve(int x, int y) {
    int l = pop(x), r = pop(y);
    l = merge(l, x);
    r = merge(r, y);
    l = merge(l, r);
    printf("%d\n", top(l));
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        init();
        up(i, 1, n) scanf("%d", &v[i]);
        scanf("%d", &m);
        up(i, 1, m) {
            scanf("%d%d", &x, &y);
            int fx = find(x), fy = find(y);
            if (fx == fy)
                printf("-1\n");
            else
                solve(fx, fy);
        }
    }
    return 0;
}