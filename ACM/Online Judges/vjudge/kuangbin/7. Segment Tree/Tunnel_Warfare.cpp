#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

int n, m, x;
char opr;
stack<int> stk;

struct SegTreeNode {
    int l, r;
    int lmax, rmax, max;
} t[maxn << 2];

void pushUp(int o) {
    t[o].lmax = t[o << 1].lmax;
    t[o].rmax = t[o << 1 | 1].rmax;
    t[o].max = max(max(t[o << 1].max, t[o << 1 | 1].max),
                   t[o << 1].rmax + t[o << 1 | 1].lmax);
    if (t[o << 1].lmax == t[o << 1].r - t[o << 1].l + 1)
        t[o].lmax += t[o << 1 | 1].lmax;
    if (t[o << 1 | 1].rmax == t[o << 1 | 1].r - t[o << 1 | 1].l + 1)
        t[o].rmax += t[o << 1].rmax;
}

void build(int o, int l, int r) {
    t[o].l = l, t[o].r = r;
    if (l == r)
        t[o].lmax = t[o].rmax = t[o].max = 1;
    else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o);
    }
}

int query(int o, int l, int r, int p) {
    if (l == r || t[o].max == r - l + 1 || t[o].max == 0) return t[o].max;
    int mid = (l + r) >> 1;
    if (p <= mid) {
        if (p >= t[o << 1].r - t[o << 1].rmax + 1)
            return query(o << 1, l, mid, p) +
                   query(o << 1 | 1, mid + 1, r, mid + 1);
        else
            return query(o << 1, l, mid, p);
    } else {
        if (p <= t[o << 1 | 1].l + t[o << 1 | 1].lmax - 1)
            return query(o << 1 | 1, mid + 1, r, p) + query(o << 1, l, mid, mid);
        else
            return query(o << 1 | 1, mid + 1, r, p);
    }
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].lmax = t[o].rmax = t[o].max = val == 1 ? 1 : 0;
        return;
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &m)) {
        while (!stk.empty()) stk.pop();
        build(1, 1, n);
        up(i, 1, m) {
            scanf("\n%c", &opr);
            if (opr == 'D') {
                scanf("%d", &x);
                update(1, 1, n, x, 0);
                stk.push(x);
            } else if (opr == 'R') {
                int top = stk.top();
                stk.pop();
                update(1, 1, n, top, 1);
            } else {
                scanf("%d", &x);
                printf("%d\n", query(1, 1, n, x));
            }
        }
    }

    return 0;
}