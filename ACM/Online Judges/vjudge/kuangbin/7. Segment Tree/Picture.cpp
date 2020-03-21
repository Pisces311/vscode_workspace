#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e3 + 5;
const int maxx = 2e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int l, r, h, f;
    bool operator<(const Edge& a) const { return h < a.h; }
} edge[maxn << 1];

struct SegTreeNode {
    int len, cnt, num;
    bool lc, rc;
} t[maxx << 2];

int n, x1, x2, y1, y2, top = 0;
int mi = inf, ma = -inf;

void pushUp(int o, int l, int r) {
    if (t[o].cnt) {
        t[o].len = r - l + 1;
        t[o].lc = t[o].rc = true;
        t[o].num = 1;
    } else if (l == r) {
        t[o].len = 0;
        t[o].lc = t[o].rc = false;
        t[o].num = 0;
    } else {
        t[o].len = t[o << 1].len + t[o << 1 | 1].len;
        t[o].lc = t[o << 1].lc;
        t[o].rc = t[o << 1 | 1].rc;
        t[o].num = t[o << 1].num + t[o << 1 | 1].num -
                   (t[o << 1].rc & t[o << 1 | 1].lc);
    }
}

void build(int o, int l, int r) {
    t[o].cnt = 0;
    t[o].len = 0;
    t[o].lc = t[o].rc = false;
    t[o].num = 0;
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

    scanf("%d", &n);
    up(i, 1, n) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ma = max(ma, max(x1, x2));
        mi = min(mi, min(x1, x2));
        edge[++top] = {x1, x2, y1, 1};
        edge[++top] = {x1, x2, y2, -1};
    }
    sort(edge + 1, edge + top + 1);
    int ans = 0, last = 0;
    build(1, mi, ma - 1);
    up(i, 1, top) {
        update(1, mi, ma - 1, edge[i].l, edge[i].r - 1, edge[i].f);
        ans += abs(t[1].len - last);
        last = t[1].len;
        ans += (edge[i + 1].h - edge[i].h) * 2 * t[1].num;
    }
    printf("%d\n", ans);

    return 0;
}