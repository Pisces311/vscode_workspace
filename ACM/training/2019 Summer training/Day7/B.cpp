#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxn << 1];

struct SegTreeNode {
    int val;
} t[maxn << 2];

int head[maxn];
int T, N, u, v, w, tot, order, a[maxn], b[maxn];
int deep[maxn], fa[maxn], son[maxn], num[maxn], top[maxn], id[maxn];
char op[10];

inline void init() {
    tot = 0;
    order = 0;
    memset(head, -1, sizeof(head));
    memset(son, 0, sizeof(son));
    memset(id, 0, sizeof(id));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

int dfs1(int u, int pre, int depth, int val) {
    deep[u] = depth;
    fa[u] = pre;
    num[u] = 1;
    b[u] = val;
    int maxson = -1;
    link(i, u) {
        int v = edge[i].v;
        if (v == pre) continue;
        num[u] += dfs1(v, u, depth + 1, edge[i].w);
        if (num[v] > maxson) {
            maxson = num[v];
            son[u] = v;
        }
    }
    return num[u];
}

void dfs2(int u, int topf) {
    id[u] = ++order;
    top[u] = topf;
    a[order] = b[u];
    if (!son[u]) return;
    dfs2(son[u], topf);
    link(i, u) {
        int v = edge[i].v;
        if (!id[v]) dfs2(v, v);
    }
}

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

void build(int o, int l, int r) {
    if (l == r) {
        t[o].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    pushUp(o, l, r);
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].val = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

int query(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return -inf;
    if (ul <= l && r <= ur) return t[o].val;
    int mid = (l + r) >> 1;
    return max(query(o << 1, l, mid, ul, ur),
               query(o << 1 | 1, mid + 1, r, ul, ur));
}

void tree_max(int x, int y) {
    int ans = -inf;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans = max(ans, query(1, 1, N, id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    ans = max(ans, query(1, 1, N, id[son[x]], id[y]));
    printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        init();
        up(i, 1, N - 1) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        dfs1(1, 0, 1, -inf);
        dfs2(1, 1);
        build(1, 1, N);
        while (true) {
            scanf("%s", op + 1);
            if (op[1] == 'D') break;
            scanf("%d %d", &u, &v);
            if (op[1] == 'C') {
                u = 2 * u - 1;
                int tmp = fa[edge[u].v] == edge[u].u ? edge[u].v : edge[u].u;
                update(1, 1, N, id[tmp], v);
            } else
                tree_max(u, v);
        }
    }

    return 0;
}