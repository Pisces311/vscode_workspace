#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

struct SegTreeNode {
    int val, size, pre;
} t[maxn << 2];

int head[maxn];
int N, M, R, P, u, v, tot, order, a[maxn], b[maxn];
int deep[maxn], fa[maxn], son[maxn], num[maxn], top[maxn], idx[maxn];

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
    idx[u] = ++order;
    a[order] = b[u];
    top[u] = topf;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!idx[v]) dfs2(v, v);
    }
}

void pushUp(int o, int l, int r) {
    t[o].val = (t[o << 1].val + t[o << 1 | 1].val + P) % P;
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
    if (!t[o].pre) return;
    t[o << 1].val = (t[o << 1].val + t[o << 1].size * t[o].pre) % P;
    t[o << 1 | 1].val = (t[o << 1 | 1].val + t[o << 1 | 1].size * t[o].pre) % P;
    t[o << 1].pre = (t[o << 1].pre + t[o].pre) % P;
    t[o << 1 | 1].pre = (t[o << 1 | 1].pre + t[o].pre) % P;
    t[o].pre = 0;
}

void update_range(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].val += t[o].size * val;
        t[o].pre += val;
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update_range(o << 1, l, mid, ul, ur, val);
    update_range(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

void TreeAdd(int x, int y, int val) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        update_range(1, 1, N, idx[top[x]], idx[x], val);
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    update_range(1, 1, N, idx[x], idx[y], val);
}

int query_range(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return 0;
    if (ul <= l && r <= ur) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return (query_range(o << 1, l, mid, ul, ur) % P +
            query_range(o << 1 | 1, mid + 1, r, ul, ur) % P) %
           P;
}

void TreeSum(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans = (ans + query_range(1, 1, N, idx[top[x]], idx[x])) % P;
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    ans = (ans + query_range(1, 1, N, idx[x], idx[y])) % P;
    printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "val", stdout);
#endif

    scanf("%d %d %d %d", &N, &M, &R, &P);
    init();
    for (int i = 1; i <= N; ++i) scanf("%d", &b[i]);
    for (int i = 1; i <= N - 1; ++i) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(R, 0, 1);
    dfs2(R, R);
    build(1, 1, N);
    while (M--) {
        int opt, x, y, z;
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d %d %d", &x, &y, &z);
            z = z % P;
            TreeAdd(x, y, z);
        } else if (opt == 2) {
            scanf("%d %d", &x, &y);
            TreeSum(x, y);
        } else if (opt == 3) {
            scanf("%d %d", &x, &z);
            update_range(1, 1, N, idx[x], idx[x] + num[x] - 1, z % P);
        } else if (opt == 4) {
            scanf("%d", &x);
            printf("%d\n",
                   query_range(1, 1, N, idx[x], idx[x] + num[x] - 1) % P);
        }
    }
    return 0;
}