#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 4e4 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int val, lazy;
} tree[4 * maxn];

struct poster {
    int l, r;
} p[maxn];

int c, n, u, v, cnt, ans;
int dc[2 * maxn], col[maxn];

inline void init() {
    ans = cnt = 0;
    mem(col, 0);
}

void pushUp(int root) {
    if (tree[root << 1].val == tree[root << 1 | 1].val)
        tree[root].val = tree[root << 1].val;
    else
        tree[root].val = 0;
}

void build(int root, int l, int r) {
    tree[root].lazy = 0;
    if (l == r) {
        tree[root].val = 0;
    } else {
        int mid = (l + r) >> 1;
        build(root << 1, l, mid);
        build(root << 1 | 1, mid + 1, r);
        pushUp(root);
    }
}

void pushDown(int root) {
    if (tree[root].lazy != 0) {
        tree[root << 1].lazy = tree[root].lazy;
        tree[root << 1 | 1].lazy = tree[root].lazy;
        tree[root << 1].val = tree[root].lazy;
        tree[root << 1 | 1].val = tree[root].lazy;
        tree[root].lazy = 0;
    }
}

void query(int root, int l, int r) {
    if (tree[root].val != 0) {
        ++col[tree[root].val];
        return;
    }
    if (l == r) return;
    pushDown(root);
    int mid = (l + r) >> 1;
    query(root << 1, l, mid);
    query(root << 1 | 1, mid + 1, r);
}

void update(int root, int l, int r, int ul, int ur, int val) {
    if (ul > r || ur < l) return;
    if (ul <= l && ur >= r) {
        tree[root].lazy = val;
        tree[root].val = val;
        return;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    update(root << 1, l, mid, ul, ur, val);
    update(root << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(root);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        init();
        up(i, 1, n) {
            scanf("%d %d", &p[i].l, &p[i].r);
            dc[++cnt] = p[i].l;
            dc[++cnt] = p[i].r;
        }
        sort(dc + 1, dc + cnt + 1);
        int tmp = unique(dc + 1, dc + cnt + 1) - dc - 1;
        int m = tmp;
        up(i, 2, tmp) if (dc[i] - dc[i - 1] > 1) dc[++m] = dc[i - 1] + 1;
        sort(dc + 1, dc + m + 1);
        build(1, 1, m);
        up(i, 1, n) {
            p[i].l = lower_bound(dc + 1, dc + m + 1, p[i].l) - dc;
            p[i].r = lower_bound(dc + 1, dc + m + 1, p[i].r) - dc;
            update(1, 1, m, p[i].l, p[i].r, i);
        }
        query(1, 1, m);
        up(i, 1, n) if (col[i])++ ans;
        printf("%d\n", ans);
    }

    return 0;
}