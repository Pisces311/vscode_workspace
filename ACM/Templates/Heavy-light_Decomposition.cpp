#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

struct SegTreeNode {
    int val, size, lazy;
} t[maxn << 2];

// depth[]：节点深度，fa[]：父节点，son[]：重儿子，num[]：节点子树的大小
// b[]:每个节点输入的值，a[]:节点重新编号后的值，id[]:每个节点重编号之后的序号
// top[]:每条链的顶端
int head[maxn];
int N, R, u, v, tot, order, a[maxn], b[maxn];
int depth[maxn], fa[maxn], son[maxn], num[maxn], top[maxn], id[maxn];

inline void init() {
    tot = -1;
    order = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

void dfs1(int u, int pre, int d) {
    depth[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == pre) continue;
        dfs1(v, u, d + 1);
        num[u] += num[v];
        if (!son[u] || num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int topf) {
    id[u] = ++order;
    a[order] = b[u];
    top[u] = topf;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!id[v]) dfs2(v, v);
    }
}

void pushUp(int o, int l, int r) {
    t[o].val = t[o << 1].val + t[o << 1 | 1].val;
}

void build(int o, int l, int r) {
    t[o].size = r - l + 1;
    if (l == r) {
        t[o].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    pushUp(o, l, r);
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy) {
        t[o << 1].val = t[o << 1].val + t[o << 1].size * t[o].lazy;
        t[o << 1 | 1].val = t[o << 1 | 1].val + t[o << 1 | 1].size * t[o].lazy;
        t[o << 1].lazy = t[o << 1].lazy + t[o].lazy;
        t[o << 1 | 1].lazy = t[o << 1 | 1].lazy + t[o].lazy;
        t[o].lazy = 0;
    }
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].val += t[o].size * val;
        t[o].lazy += val;
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

void pathAdd(int x, int y, int val) {
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]]) swap(x, y);
        update(1, 1, N, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y]) swap(x, y);
    update(1, 1, N, id[x], id[y], val);
}

int query(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return 0;
    if (ul <= l && r <= ur) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return query(o << 1, l, mid, ul, ur) +
           query(o << 1 | 1, mid + 1, r, ul, ur);
}

int pathSum(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]]) swap(x, y);
        ans += query(1, 1, N, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y]) swap(x, y);
    ans += query(1, 1, N, id[x],
                 id[y]);  //注意：如果是点权则不变，边权则改为id[son[x]]
    return ans;
}