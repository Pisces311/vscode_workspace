#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e2 + 5;

struct node {
    int v, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int T, n, m, u, v, query, des;
int bus[maxn], dis[maxn], cnt[maxn];
vector<node> g[maxn];
queue<int> q;
bool vis[maxn], neg[maxn];

int get_dis(int u, int v) { return pow(bus[v] - bus[u], 3); }

void dfs(int v) {
    neg[v] = true;
    up(i, 0, (int)g[v].size() - 1) if (!neg[g[v][i].v]) dfs(g[v][i].v);
}

void spfa() {
    up(i, 1, n) dis[i] = INT_MAX;
    mem(neg, false);
    mem(cnt, 0);
    dis[1] = 0;
    q.push(1);
    ++cnt[1];
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;
        if (neg[f]) continue;
        up(i, 0, (int)g[f].size() - 1) if (!neg[g[f][i].v]) {
            int v = g[f][i].v;
            if (dis[v] > dis[f] + g[f][i].dis) {
                dis[v] = dis[f] + g[f][i].dis;
                if (!vis[v]) {
                    ++cnt[v];
                    if (cnt[v] > n)
                        dfs(v);
                    else {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    up(k, 1, T) {
        scan(n);
        up(i, 1, n) scan(bus[i]);
        up(i, 1, n) g[i].clear();
        scan(m);
        up(i, 1, m) {
            scanf("%d %d", &u, &v);
            g[u].push_back({v, get_dis(u, v)});
        }
        spfa();
        printf("Case %d:\n", k);
        scan(query);
        up(i, 1, query) {
            scan(des);
            if (dis[des] < 3 || neg[des] || dis[des] == INT_MAX)
                printf("?\n");
            else
                print(dis[des]);
        }
    }

    return 0;
}