#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

struct SegTreeNode {
    int val, lazy;
} t[maxn << 2];

int n, q;

// deep[]：节点深度，fa[]：父节点，son[]：重儿子，num[]：节点子树的大小
// b[]:每个节点输入的值，a[]:节点重新编号后的值，id[]:每个节点重编号之后的序号
// top[]:每条链的顶端
int head[maxn];
int tot, order, a[maxn], b[maxn];
int deep[maxn], fa[maxn], son[maxn], num[maxn], top[maxn], id[maxn];

inline void init() {
    tot = -1;
    order = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

int dfs1(int u, int pre, int depth) {
    deep[u] = depth;
    fa[u] = pre;
    num[u] = 1;
    int maxson = -1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == pre) continue;
        num[u] += dfs1(v, u, depth + 1);
        if (num[v] > maxson) {
            maxson = num[v];
            son[u] = v;
        }
    }
    return num[u];
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

void build(int o, int l, int r) {
    t[o].lazy = -1;
    if (l == r) {
        t[o].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy != -1) {
        t[o << 1].val = t[o << 1 | 1].val = t[o].lazy;
        t[o << 1].lazy = t[o << 1 | 1].lazy = t[o].lazy;
        t[o].lazy = -1;
    }
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].val = val;
        t[o].lazy = val;
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
}

void pathAdd(int x, int y, int val) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y], val);
}

int query(int o, int l, int r, int p) {
    if (r < p || p < l) return 0;
    if (p <= l && r <= p) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return query(o << 1, l, mid, p) + query(o << 1 | 1, mid + 1, r, p);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            update(1, 1, n, id[x], id[x] + num[x] - 1, 1);
        } else if (opt == 2) {
            pathAdd(1, x, 0);
        } else {
            cout << query(1, 1, n, id[x]) << '\n';
        }
    }

    return 0;
}