#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

struct node {
    int v, w;
    friend bool operator<(const node& a, const node& b) { return a.w < b.w; }
};

int T, n, m, ans;
bool vis[maxn];
vector<pii> g[maxn];
priority_queue<node> pq;

inline void init() {
    ans = INT_MAX;
    up(i, 1, maxn) g[i].clear();
    memset(vis, false, sizeof(vis));
    while (!pq.empty()) pq.pop();
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    up(i, 1, T){
        init();
        scanf("%d %d", &n, &m);
        int u, v, w;
        up(j, 1, m){
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
        pq.push({1, INT_MAX});
        while (1) {
            node top = pq.top();
            pq.pop();
            if (vis[top.v]) continue;
            vis[top.v] = true;
            ans = min(ans, top.w);
            if (top.v == n) break;
            up(j, 0, (int)g[top.v].size() - 1) if (!vis[g[top.v][j].first]) {
                pq.push({g[top.v][j].first, g[top.v][j].second});
            }
        }
        printf("Scenario #%d:\n%d\n\n", i, ans);
    }

    return 0;
}