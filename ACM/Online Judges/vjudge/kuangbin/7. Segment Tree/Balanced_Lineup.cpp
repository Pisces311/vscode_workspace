#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int val, min, max;
} tree[4 * maxn];

int N, Q, u, v;
int a[maxn];

void pushUp(int root) {
    tree[root].min = min(tree[root << 1].min, tree[root << 1 | 1].min);
    tree[root].max = max(tree[root << 1].max, tree[root << 1 | 1].max);
}

void build(int root, int arr[], int l, int r) {
    if (l == r) {
        tree[root].val = arr[l];
        tree[root].min = arr[l];
        tree[root].max = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(root << 1, arr, l, mid);
        build(root << 1 | 1, arr, mid + 1, r);
        pushUp(root);
    }
}

int query_max(int root, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[root].max;
    int mid = (l + r) >> 1;
    return max(query_max(root << 1, l, mid, ql, qr),
               query_max(root << 1 | 1, mid + 1, r, ql, qr));
}

int query_min(int root, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return inf;
    if (ql <= l && r <= qr) return tree[root].min;
    int mid = (l + r) >> 1;
    return min(query_min(root << 1, l, mid, ql, qr),
               query_min(root << 1 | 1, mid + 1, r, ql, qr));
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &Q);
    up(i, 1, N) scanf("%d", &a[i]);
    build(1, a, 1, N);
    up(i, 1, Q) {
        scanf("%d %d", &u, &v);
        printf("%d\n", query_max(1, 1, N, u, v) - query_min(1, 1, N, u, v));
    }

    return 0;
}