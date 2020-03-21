#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    double len;
    int cnt;
} t[maxn << 3];

struct Edge {
    double l, r, h;
    int f;
    bool operator<(const Edge& a) const { return h < a.h; }
} edge[maxn << 1];

int n, tot, top;
double dc[maxn << 1];
double x1, y1, x2, y2;

inline void init() { tot = top = 0; }

void pushUp(int o, int l, int r) {
    if (t[o].cnt)
        t[o].len = dc[r + 1] - dc[l];
    else if (l == r)
        t[o].len = 0;
    else
        t[o].len = t[o << 1].len + t[o << 1 | 1].len;
}

void build(int o, int l, int r) {
    t[o].len = 0;
    t[o].cnt = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].cnt += val;
        pushUp(o, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int case_num = 0;
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        init();
        printf("Test case #%d\nTotal explored area: ", ++case_num);
        up(i, 1, n) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            edge[++tot] = {x1, x2, y1, 1};
            edge[++tot] = {x1, x2, y2, -1};
            dc[++top] = x1;
            dc[++top] = x2;
        }
        sort(edge + 1, edge + tot + 1);
        sort(dc + 1, dc + top + 1);
        int m = unique(dc + 1, dc + top + 1) - dc - 1;
        build(1, 1, m);
        double ans = 0;
        up(i, 1, tot) {
            int l = lower_bound(dc + 1, dc + m + 1, edge[i].l) - dc;
            int r = lower_bound(dc + 1, dc + m + 1, edge[i].r) - dc;
            update(1, 1, m, l, r - 1, edge[i].f);
            ans += (edge[i + 1].h - edge[i].h) * t[1].len;
        }
        printf("%.2f\n\n", ans);
    }

    return 0;
}