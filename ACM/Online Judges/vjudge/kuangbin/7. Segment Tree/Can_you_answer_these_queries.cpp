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
    ll val;
} tree[4 * maxn];

int N, M, T, X, Y;
ll a[maxn];

void pushUp(int root) {
    tree[root].val = tree[root << 1].val + tree[root << 1 | 1].val;
}

void build(int root, ll arr[], int l, int r) {
    if (l == r)
        tree[root].val = arr[l];
    else {
        int mid = (l + r) >> 1;
        build(root << 1, arr, l, mid);
        build(root << 1 | 1, arr, mid + 1, r);
        pushUp(root);
    }
}

ll query(int root, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[root].val;
    int mid = (l + r) >> 1;
    return (query(root << 1, l, mid, ql, qr) +
            query(root << 1 | 1, mid + 1, r, ql, qr));
}

void update(int root, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        if (tree[root].val == r - l + 1)
            return;
        else if (l == r) {
            tree[root].val = sqrt(tree[root].val);
            return;
        }
    }
    int mid = (l + r) >> 1;
    update(root << 1, l, mid, ul, ur);
    update(root << 1 | 1, mid + 1, r, ul, ur);
    pushUp(root);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int case_num = 0;
    while (~scanf("%d", &N)) {
        printf("Case #%d:\n", ++case_num);
        up(i, 1, N) scanf("%lld", &a[i]);
        build(1, a, 1, N);
        scanf("%d", &M);
        up(i, 1, M) {
            scanf("%d %d %d", &T, &X, &Y);
            if (Y < X) swap(X, Y);
            if (T == 0) update(1, 1, N, X, Y);
            if (T == 1) printf("%lld\n", query(1, 1, N, X, Y));
        }
        printf("\n");
    }

    return 0;
}