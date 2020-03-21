#include <string.h>
#include <iostream>
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

const int maxp = 5e1 + 5;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int P, R, ans;
bool vis[maxp];
vector<node> g[maxp];
priority_queue<node> pq;

inline void init() {
    ans = 0;
    up(i, 1, P) g[i].clear();
    mem(vis, false);
}

void prim() {
    pq.push({1, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        ans += t.w;
        up(i, 0, (int)g[t.v].size() - 1) if (!vis[g[t.v][i].v]) {
            int v = g[t.v][i].v;
            pq.push({v, g[t.v][i].w});
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> P && P) {
        cin >> R;
        init();
        int u, v, w;
        up(i, 1, R) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        prim();
        cout << ans << endl;
    }

    return 0;
}