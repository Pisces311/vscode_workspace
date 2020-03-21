#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 8e3 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int val, lazy;
} tree[4 * maxn];

int n, x1, x2, c, last;
int col[maxn];

inline void init() {
    mem(col, 0);
    last = inf;
}

void pushUp(int root) {
    if (tree[root << 1].val == tree[root << 1 | 1].val)
        tree[root].val = tree[root << 1].val;
    else
        tree[root].val = inf;
}

void pushDown(int root) {
    if (tree[root].lazy != inf) {
        tree[root << 1].lazy = tree[root].lazy;
        tree[root << 1 | 1].lazy = tree[root].lazy;
        tree[root << 1].val = tree[root].lazy;
        tree[root << 1 | 1].val = tree[root].lazy;
        tree[root].lazy = inf;
    }
}

void build(int root, int l, int r) {
    tree[root].lazy = inf;
    if (l == r)
        tree[root].val = inf;
    else {
        int mid = (l + r) >> 1;
        build(root << 1, l, mid);
        build(root << 1 | 1, mid + 1, r);
        pushUp(root);
    }
}

void query(int root, int l, int r) {
    if (tree[root].val != inf) {
        if (last != tree[root].val) {
            last = tree[root].val;
            ++col[tree[root].val];
        }
        return;
    }
    if (l == r) {
        last = inf;
        return;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    query(root << 1, l, mid);
    query(root << 1 | 1, mid + 1, r);
}

void update(int root, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
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

    while (~scanf("%d", &n)) {
        init();
        build(1, 1, 8000);
        up(i, 1, n) {
            scanf("%d %d %d", &x1, &x2, &c);
            ++x1;
            update(1, 1, 8000, x1, x2, c);
        }
        query(1, 1, 8000);
        up(i, 0, 8000) if (col[i]) printf("%d %d\n", i, col[i]);
        printf("\n");
    }

    return 0;
}