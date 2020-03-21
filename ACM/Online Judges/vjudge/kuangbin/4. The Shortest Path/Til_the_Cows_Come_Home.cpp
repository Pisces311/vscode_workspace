#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <vector>
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
    node(int v, int w):v(v), w(w) {}
    friend bool operator<(const node& a, const node& b) { return a.w > b.w; }
};

int T, N;
int dis[maxn];
vector<node> g[maxn];
bool vis[maxn];
priority_queue<node> pq;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T >> N;
    up(i, 1, T) { 
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(node(v, w));
        g[v].push_back(node(u, w));
    }
    up(i, 1, N) dis[i] = INT_MAX;
    pq.push(node(N, 0));
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        vis[top.v] = true;
        up(i, 0, (int)g[top.v].size() - 1)if(!vis[g[top.v][i].v]){
            node x = g[top.v][i];
            if(dis[x.v]>x.w+top.w){
                dis[x.v] = x.w + top.w;
                pq.push(node(x.v, dis[x.v]));
            }
        }
    }
    cout << dis[1] << endl;

    return 0;
}