#include <stdio.h>
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

const int maxn = 1e2 + 5;

struct node {
    int v;
    double R, C;
    node(int v, double R, double C) : v(v), R(R), C(C) {}
};

int N, M, S;
double V;
vector<node> g[maxn];
bool vis[maxn];
double dis[maxn];
queue<int> q;

bool spfa(int S) {
    dis[S] = V;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;
        up(i, 0, (int)g[f].size() - 1) {
            int v = g[f][i].v;
            if (dis[v] < (dis[f] - g[f][i].C) * g[f][i].R) {
                dis[v] = (dis[f] - g[f][i].C) * g[f][i].R;
                if (dis[S] > V) return true;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d %d %lf", &N, &M, &S, &V);
    int a, b;
    double c, d, e, f;
    up(i, 1, M) {
        scanf("%d %d %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
        g[a].push_back({b, c, d});
        g[b].push_back({a, e, f});
    }
    if (spfa(S))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}