#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int val, lazy, size;
} tree[4 * maxn];

int t, N, Q, u, v, w;

void pushUp(int root) {
    tree[root].val = tree[root << 1].val + tree[root << 1 | 1].val;
    tree[root].size = tree[root << 1].size + tree[root << 1 | 1].size;
}

void pushDown(int root) {
    if (tree[root].lazy != 0) {
        tree[root << 1].lazy = tree[root].lazy;
        tree[root << 1 | 1].lazy = tree[root].lazy;
        tree[root << 1].val = tree[root].lazy * tree[root << 1].size;
        tree[root << 1 | 1].val = tree[root].lazy * tree[root << 1 | 1].size;
        tree[root].lazy = 0;
    }
}

void build(int root, int l, int r) {
    tree[root].lazy = 0;
    if (l == r) {
        tree[root].val = 1;
        tree[root].size = 1;
    } else {
        int mid = (l + r) >> 1;
        build(root << 1, l, mid);
        build(root << 1 | 1, mid + 1, r);
        pushUp(root);
    }
}

int query(int root, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[root].val;
    pushDown(root);
    int mid = (l + r) >> 1;
    return (query(root << 1, l, mid, ql, qr) +
            query(root << 1 | 1, mid + 1, r, ql, qr));
}

void update(int root, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        tree[root].lazy = val;
        tree[root].val = val * tree[root].size;
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

    scanf("%d", &t);
    up(case_num, 1, t) {
        scanf("%d %d", &N, &Q);
        build(1, 1, N);
        up(i, 1, Q) {
            scanf("%d %d %d", &u, &v, &w);
            update(1, 1, N, u, v, w);
        }
        printf("Case %d: The total value of the hook is %d.\n", case_num,
               query(1, 1, N, 1, N));
    }

    return 0;
}