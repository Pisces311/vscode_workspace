#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int l, r, h, f;
    bool operator<(const Edge& a) const { return h < a.h; }
} edge[maxn << 1];

struct Node {
    int cnt;
    int len1, len2, len3;
} t[maxn << 3];

struct Point {
    int x, y, z;
} a[maxn];

int T, n, totx, totz, tot;
int x1, y1, z1, x2, y2, z2;
int x[maxn << 1], z[maxn << 1];

inline void init() { totx = totz = tot = 0; }

void pushup(int o, int l, int r) {
    if (t[o].cnt >= 3) {
        t[o].len3 = x[r + 1] - x[l];
        t[o].len1 = t[o].len2 = 0;
    } else if (t[o].cnt >= 2) {
        t[o].len3 = t[o << 1].len3 + t[o << 1 | 1].len3 + t[o << 1].len2 +
                    t[o << 1 | 1].len2 + t[o << 1].len1 + t[o << 1 | 1].len1;
        t[o].len2 = x[r + 1] - x[l] - t[o].len3;
        t[o].len1 = 0;
    } else if (t[o].cnt >= 1) {
        t[o].len3 = t[o << 1].len3 + t[o << 1 | 1].len3 + t[o << 1].len2 +
                    t[o << 1 | 1].len2;
        t[o].len2 = t[o << 1].len1 + t[o << 1 | 1].len1;
        t[o].len1 = x[r + 1] - x[l] - t[o].len3 - t[o].len2;
    } else {
        t[o].len3 = t[o << 1].len3 + t[o << 1 | 1].len3;
        t[o].len2 = t[o << 1].len2 + t[o << 1 | 1].len2;
        t[o].len1 = t[o << 1].len1 + t[o << 1 | 1].len1;
    }
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].cnt += val;
        pushup(o, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushup(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_no, 1, T) {
        scanf("%d", &n);
        init();
        up(i, 1, n) {
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            x[++totx] = x1;
            x[++totx] = x2;
            z[++totz] = z1;
            z[++totz] = z2;
            a[++tot] = {x1, y1, z1};
            a[++tot] = {x2, y2, z2};
        }
        printf("Case %d: ", case_no);
        if (n < 3) {
            puts("0");
            continue;
        }
        sort(x + 1, x + totx + 1);
        sort(z + 1, z + totz + 1);
        totx = unique(x + 1, x + totx + 1) - x - 1;
        totz = unique(z + 1, z + totz + 1) - z - 1;
        ll ans = 0;
        up(i, 1, totz - 1) {
            int k = 0;
            up(j, 1, tot) {
                if (a[j].z <= z[i] && a[j + 1].z > z[i]) {
                    edge[++k] = {a[j].x, a[j + 1].x, a[j].y, 1};
                    edge[++k] = {a[j].x, a[j + 1].x, a[j + 1].y, -1};
                }
                ++j;
            }
            sort(edge + 1, edge + k + 1);
            mem(t, 0);
            ll tmp = 0;
            up(j, 1, k - 1) {
                int l = lower_bound(x + 1, x + totx + 1, edge[j].l) - x;
                int r = lower_bound(x + 1, x + totx + 1, edge[j].r) - x - 1;
                update(1, 1, totx, l, r, edge[j].f);
                tmp += 1ll * t[1].len3 * (edge[j + 1].h - edge[j].h);
            }
            ans += tmp * (z[i + 1] - z[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}