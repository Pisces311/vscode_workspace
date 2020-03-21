#include <algorithm>
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

struct node{
    int v, w;
    node(int v, int w):v(v), w(w){}
    friend bool operator<(const node& a, const node& b) { return a.w > b.w; }
};

int N, M, X;
int dis[maxn];
bool vis[maxn];
vector<pii> g[maxn], ng[maxn];
priority_queue<node> pq, pq2;

void dijkstra(){
    pq.push({X, 0});
    while(!pq.empty()){
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        else
            vis[t.v] = true;
        dis[t.v] += t.w;
        up(i, 0, (int)g[t.v].size() - 1)if(!vis[g[t.v][i].first]){
            pq.push({g[t.v][i].first, g[t.v][i].second + t.w});
        }
    }
}

void dijkstra2() {
    pq2.push({X, 0});
    while (!pq2.empty()) {
        node t = pq2.top();
        pq2.pop();
        if (vis[t.v])
            continue;
        else
            vis[t.v] = true;
        dis[t.v] += t.w;
        up(i, 0, (int)ng[t.v].size() - 1) if (!vis[ng[t.v][i].first]) {
            pq2.push({ng[t.v][i].first, ng[t.v][i].second + t.w});
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d %d", &N, &M, &X);
    int u, v, w;
    up(i, 1, M){
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        ng[v].push_back(make_pair(u, w));
    }
    dijkstra();
    memset(vis, false, sizeof(vis));
    dijkstra2();
    printf("%d\n", *max_element(dis + 1, dis + N + 1));

    return 0;
}