#include <stdio.h>
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
    int mark, size;
} tree[4 * maxn];

int N, Q, u, v, w;
char opr;
int a[maxn];

/*
功能：构建线段树
root：当前线段树的根节点下标
arr: 用来构造线段树的数组
l：数组的起始位置
r：数组的结束位置
*/
void build(int root, int arr[], int l, int r) {
    tree[root].mark = 0;
    if (l == r) {
        tree[root].val = arr[l];
        tree[root].size = 1;
    } else {
        int mid = (l + r) / 2;
        build(root * 2, arr, l, mid);
        build(root * 2 + 1, arr, mid + 1, r);
        tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
        tree[root].size = tree[root * 2].size + tree[root * 2 + 1].size;
    }
}

/*
功能：当前节点的标志域向孩子节点传递
root: 当前线段树的根节点下标
*/
void pushDown(int root) {
    if (tree[root].mark != 0) {
        tree[root * 2].mark += tree[root].mark;
        tree[root * 2 + 1].mark += tree[root].mark;
        tree[root * 2].val += 1ll * tree[root].mark * tree[root * 2].size;
        tree[root * 2 + 1].val +=
            1ll * tree[root].mark * tree[root * 2 + 1].size;
        tree[root].mark = 0;
    }
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nl, nr]: 当前节点所表示的区间
[ql, qr]: 此次查询的区间
*/
ll query(int root, int nl, int nr, int ql, int qr) {
    if (ql > nr || qr < nl) return 0;
    if (ql <= nl && qr >= nr) return tree[root].val;
    pushDown(root);
    int mid = (nl + nr) / 2;
    return (query(root * 2, nl, mid, ql, qr) +
            query(root * 2 + 1, mid + 1, nr, ql, qr));
}

/*
功能：更新线段树中某个区间内叶子节点的值
root：当前线段树的根节点下标
[nl, nr]: 当前节点所表示的区间
[ul, ur]: 待更新的区间
lazy: 更新的值（原来的值加上lazy）
*/
void update(int root, int nl, int nr, int ul, int ur, int lazy) {
    if (ul > nr || ur < nl) return;
    if (ul <= nl && ur >= nr) {
        tree[root].mark += lazy;
        tree[root].val += lazy * tree[root].size;
        return;
    }
    pushDown(root);
    int mid = (nl + nr) / 2;
    update(root * 2, nl, mid, ul, ur, lazy);
    update(root * 2 + 1, mid + 1, nr, ul, ur, lazy);
    tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
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
        scanf("\n%c", &opr);
        if (opr == 'C') {
            scanf("%d %d %d", &u, &v, &w);
            update(1, 1, N, u, v, w);
        }
        if (opr == 'Q') {
            scanf("%d %d", &u, &v);
            printf("%lld\n", query(1, 1, N, u, v));
        }
    }

    return 0;
}