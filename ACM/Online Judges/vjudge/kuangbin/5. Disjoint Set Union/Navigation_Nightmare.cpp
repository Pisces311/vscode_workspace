#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 4e4 + 5;
const int maxm = 4e4 + 5;
const int maxk = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct info {
    int u, v, w;
    char dir;
} in[maxm];

struct query {
    int u, v, t, in, ans;
    bool operator<(const query& a) const { return t < a.t; }
} q[maxk];

int N, M, K, u, v, t;
int fa[maxn], e[maxn], n[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    int root = find(fa[x]);
    e[x] += e[fa[x]];
    n[x] += n[fa[x]];
    return fa[x] = root;
}

bool cmp(const query& a, const query& b) { return a.in < b.in; }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    up(i, 1, M) scanf("%d %d %d %c", &in[i].u, &in[i].v, &in[i].w, &in[i].dir);
    scanf("%d", &K);
    up(i, 1, K) scanf("%d %d %d", &q[i].u, &q[i].v, &q[i].t);
    up(i, 1, K) q[i].in = i;
    sort(q + 1, q + K + 1);
    up(i, 1, N) fa[i] = i;
    int cur = 1;
    up(i, 1, K) {
        while (cur <= M && q[i].t >= cur) {
            u = in[cur].u, v = in[cur].v;
            int x = find(u), y = find(v);
            if (x != y) {
                fa[y] = x;
                if (in[cur].dir == 'E') {
                    e[y] = e[u] - e[v] + in[cur].w;
                    n[y] = n[u] - n[v];
                } else if (in[cur].dir == 'W') {
                    e[y] = e[u] - e[v] - in[cur].w;
                    n[y] = n[u] - n[v];
                } else if (in[cur].dir == 'N') {
                    n[y] = n[u] - n[v] + in[cur].w;
                    e[y] = e[u] - e[v];
                } else {
                    n[y] = n[u] - n[v] - in[cur].w;
                    e[y] = e[u] - e[v];
                }
            }
            ++cur;
        }
        int x = find(q[i].u), y = find(q[i].v);
        if (x != y)
            q[i].ans = -1;
        else
            q[i].ans = abs(e[q[i].u] - e[q[i].v]) + abs(n[q[i].u] - n[q[i].v]);
    }
    sort(q + 1, q + K + 1, cmp);
    up(i, 1, K) printf("%d\n", q[i].ans);

    return 0;
}