#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e6 + 5;

struct EDGE {
    int v, next;
} edge[maxn], edge0[maxn];

int N, M, A, B, Q, order, cut_edge, top, top0, front;
int dfn[maxn], low[maxn], belong[maxn], in[maxn];
int depth[maxn], fa[maxn], head[maxn], head0[maxn];
int stk[maxn];

void init() {
    top = top0 = front = 0;
    mem(head, -1);
    mem(head0, -1);
    order = cut_edge = 0;
    mem(dfn, 0);
}

inline void addedge(int u, int v, EDGE edge[], int head[], int& top) {
    edge[top] = {v, head[u]};
    head[u] = top++;
}

int find(int x) { return belong[x] == x ? x : belong[x] = find(belong[x]); }

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++order;
    stk[top++] = u;
    in[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == pre) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) cut_edge++;
        } else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        int v;
        do {
            v = stk[--top];
            in[v] = false;
            belong[v] = u;
        } while (v != u);
    }
}

void build(int u, int pre) {
    fa[u] = pre;
    depth[u] = depth[pre] + 1;
    for (int i = head0[u]; i != -1; i = edge0[i].next)
        if (edge0[i].v != pre) build(edge0[i].v, u);
}

int LCA(int u, int v) {
    if (u == v) return u;
    if (depth[u] < depth[v]) swap(u, v);
    --cut_edge;
    int lca = LCA(find(fa[u]), v);
    return belong[u] = lca;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    int case_num = 0;
    while (cin >> N >> M && (N || M)) {
        init();
        up(i, 1, M) {
            cin >> A >> B;
            addedge(A, B, edge, head, top);
            addedge(B, A, edge, head, top);
        }
        tarjan(1, 1);
        up(i, 1, N) for (int j = head[i]; j != -1; j = edge[j].next) {
            int x = find(i), y = find(edge[j].v);
            if (x != y) addedge(x, y, edge0, head0, top0);
        }
        build(find(1), find(1));
        cin >> Q;
        cout << "Case " << ++case_num << ":" << endl;
        while (Q--) {
            cin >> A >> B;
            LCA(find(A), find(B));
            cout << cut_edge << endl;
        }
        cout << endl;
    }

    return 0;
}