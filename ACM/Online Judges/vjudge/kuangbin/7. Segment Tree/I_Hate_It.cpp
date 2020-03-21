#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int val, mark, size;
} tree[4 * maxn];

int N, M, A, B;
int a[maxn];
char opr;

/*
功能：构建线段树
root：当前线段树的根节点下标
arr: 用来构造线段树的数组
istart：数组的起始位置
iend：数组的结束位置
*/
void build(int root, int arr[], int istart, int iend) {
    tree[root].mark = 0;
    if (istart == iend) {
        tree[root].val = arr[istart];
        tree[root].size = 1;
    } else {
        int mid = (istart + iend) / 2;
        build(root * 2, arr, istart, mid);
        build(root * 2 + 1, arr, mid + 1, iend);
        tree[root].val = max(tree[root * 2].val, tree[root * 2 + 1].val);
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
        tree[root * 2].val = tree[root].mark * tree[root * 2].size;
        tree[root * 2 + 1].val += tree[root].mark * tree[root * 2 + 1].size;
        tree[root].mark = 0;
    }
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/
int query(int root, int nstart, int nend, int qstart, int qend) {
    if (qstart > nend || qend < nstart) return 0;
    if (qstart <= nstart && qend >= nend) return tree[root].val;
    pushDown(root);
    int mid = (nstart + nend) / 2;
    return (max(query(root * 2, nstart, mid, qstart, qend), 
            query(root * 2 + 1, mid + 1, nend, qstart, qend)));
}

/*
功能：更新线段树中某个区间内叶子节点的值
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[ustart, uend]: 待更新的区间
addVal: 更新的值（原来的值加上addVal）
*/
void update(int root, int nstart, int nend, int ustart, int uend, int addVal) {
    if (ustart > nend || uend < nstart) return;
    if (ustart <= nstart && uend >= nend) {
        tree[root].mark = 0;
        tree[root].val = addVal;
        return;
    }
    pushDown(root);
    int mid = (nstart + nend) / 2;
    update(root * 2, nstart, mid, ustart, uend, addVal);
    update(root * 2 + 1, mid + 1, nend, ustart, uend, addVal);
    tree[root].val = max(tree[root * 2].val, tree[root * 2 + 1].val);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        up(i, 1, N) scanf("%d", &a[i]);
        build(1, a, 1, N);
        up(i, 1, M) {
            scanf("\n%c %d %d", &opr, &A, &B);
            if (opr == 'U') update(1, 1, N, A, A, B);
            if(opr=='Q')printf("%d\n", query(1, 1, N, A, B));
        }
    }

    return 0;
}