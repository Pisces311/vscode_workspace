#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct monster {
    int X, Y, S;
} mon[maxn];

int T, n, m, K;
vector<int> g[maxn];
bool vis[maxn];

inline void init() {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i <= K + 1; ++i) g[i].clear();
}

void bfs() {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m >> K;
        init();
        for (int i = 1; i <= K; ++i) cin >> mon[i].X >> mon[i].Y >> mon[i].S;
        for (int i = 1; i <= K; ++i)
            for (int j = i + 1; j <= K; ++j) {
                if (hypot(mon[i].X - mon[j].X, mon[i].Y - mon[j].Y) <=
                    mon[i].S + mon[j].S) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        for (int i = 1; i <= K; ++i)
            if (n - mon[i].X <= mon[i].S || mon[i].Y <= mon[i].S)
                g[0].push_back(i);
        for (int i = 1; i <= K; ++i)
            if (mon[i].X <= mon[i].S || m - mon[i].Y <= mon[i].S)
                g[i].push_back(K + 1);
        bfs();
        if (vis[K + 1])
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}