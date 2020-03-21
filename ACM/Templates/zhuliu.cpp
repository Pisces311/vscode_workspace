#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
} edge[maxm];

int N, M, tot;

double in[maxn];
int pre[maxn], id[maxn], vis[maxn];

// in[]：记录每个点的入边权值（求最小入边），cnt：记录（非法）树中环的个数。
// pre[]：记录前驱点，vis[]：记录本次搜索中节点属于哪一个环
double zhuliu(int rt) {
    double ans = 0;
    while (true) {
        for (int i = 1; i <= N; ++i) in[i] = inf;
        for (int i = 1; i <= tot; ++i) {
            int u = edge[i].u, v = edge[i].v;
            double w = edge[i].w;
            if (u == v)
                continue;
            else if (in[v] > w) {
                pre[v] = u;
                in[v] = w;
            }
        }
        for (int i = 1; i <= N; ++i)
            if (i != rt && in[i] == inf) return -1;
        int cnt = 0;
        memset(id, 0, sizeof(id));
        memset(vis, 0, sizeof(vis));
        in[rt] = 0;
        for (int i = 1; i <= N; ++i) {
            ans += in[i];
            int v = i;
            while (!id[v] && v != rt && vis[v] != i) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != rt && !id[v]) {
                id[v] = ++cnt;
                for (int j = pre[v]; j != v; j = pre[j]) id[j] = cnt;
            }
        }
        if (!cnt) break;
        for (int i = 1; i <= N; ++i)
            if (!id[i]) id[i] = ++cnt;
        for (int i = 1; i <= M; ++i) {
            int x = edge[i].u, y = edge[i].v;
            edge[i].u = id[x];
            edge[i].v = id[y];
            if (id[x] != id[y]) edge[i].w -= in[y];
        }
        N = cnt;
        rt = id[rt];
    }
    return ans;
}

int main() { return 0; }