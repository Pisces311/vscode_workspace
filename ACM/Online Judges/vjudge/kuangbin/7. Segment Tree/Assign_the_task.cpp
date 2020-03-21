#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn];

struct SegTreeNode {
    int val, lazy;
} t[maxn << 2];

int T, N, M, u, v, tot, order;
int head[maxn], s[maxn], e[maxn];
bool isroot[maxn];
char op[3];

inline void init() {
    tot = -1;
    order = 0;
    mem(head, -1);
    mem(isroot, true);
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

void dfs(int o) {
    s[o] = ++order;
    link(i, o) dfs(edge[i].v);
    e[o] = order;
}

void pushUp(int o) {
    if (t[o << 1].val == t[o << 1 | 1].val)
        t[o].val = t[o << 1].val;
    else
        t[o].val = -1;
}

void pushDown(int o) {
    if (t[o].lazy != -1) {
        t[o << 1].lazy = t[o].lazy;
        t[o << 1 | 1].lazy = t[o].lazy;
        t[o << 1].val = t[o].lazy;
        t[o << 1 | 1].val = t[o].lazy;
        t[o].lazy = -1;
    }
}

void build(int o, int l, int r) {
    t[o].lazy = -1;
    if (l == r)
        t[o].val = -1;
    else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o);
    }
}

int query(int o, int l, int r, int p) {
    if (r < p || p < l) return 0;
    if (l == r && l == p) return t[o].val;
    pushDown(o);
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, p) + query(o << 1 | 1, mid + 1, r, p));
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy = val;
        t[o].val = val;
        return;
    }
    pushDown(o);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_num, 1, T) {
        printf("Case #%d:\n", case_num);
        scanf("%d", &N);
        init();
        up(i, 1, N - 1) {
            scanf("%d %d", &u, &v);
            add_edge(v, u);
            isroot[u] = false;
        }
        up(i, 1, N) if (isroot[i]) {
            dfs(i);
            break;
        }
        build(1, 1, order);
        scanf("%d", &M);
        up(i, 1, M) {
            scanf("%s", op + 1);
            if (op[1] == 'C') {
                scanf("%d", &u);
                printf("%d\n", query(1, 1, order, s[u]));
            }
            if (op[1] == 'T') {
                scanf("%d %d", &u, &v);
                update(1, 1, order, s[u], e[u], v);
            }
        }
    }

    return 0;
}