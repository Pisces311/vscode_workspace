#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

int n, m, f;
bool vis[maxn], vis2[maxn];
queue<int> q;
vector<int> g[maxn], prevec;
int cx[maxn], cy[maxn];
int edge[maxn][maxn];

int line(int u) {
    for(int v: prevec) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = 1;
            if (cy[v] == -1 || line(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int maxmatch() {
    int sum = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(int i: g[f]) {
        if (cx[i] == -1) {
            memset(vis, 0, sizeof(vis));
            sum += line(i);
        }
    }
    return sum;
}

inline void pre(){
    memset(vis2, false, sizeof(vis2));
    for (int i : g[f]) vis2[i] = true;
    prevec.clear();
    up(i, 1, n)
        if (!vis2[i] && i != f) prevec.push_back(i);
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);
    int u, v;
    up(i, 1, m){
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    up(i, 1, n)
        if (2 * g[i].size() >= n - 1) q.push(i);
    bool ok = false;
    while(q.size()){
        f = q.front();
        q.pop();
        pre();
        int sum = maxmatch();
        if (sum == n - g[f].size() - 1){
            printf("Yes\n%d %d\n", f, g[f].size());
            ok = true;
            break;
        }
    }
    if(!ok){
        printf("No\n");
        return 0;
    }
    up(i, 1, n) {
        if (vis2[i]){
            if (cx[i] == -1) printf("%d -1\n", i);
            else
                printf("%d %d\n", i, cx[i]);
        }
    } 

    return 0;
}