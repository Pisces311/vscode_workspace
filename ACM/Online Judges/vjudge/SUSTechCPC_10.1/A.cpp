#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct circle {
    int X, Y, S;
} c[maxn];

int M, N, K;
vector<int> g[maxn];
bool vis[maxn];

void bfs() {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> K;
    for (int i = 1; i <= K; ++i) cin >> c[i].X >> c[i].Y >> c[i].S;
    for (int i = 1; i <= K; ++i)
        for (int j = i + 1; j <= K; ++j) {
            if (hypot(c[i].X - c[j].X, c[i].Y - c[j].Y) <= c[i].S + c[j].S) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    for (int i = 1; i <= K; ++i)
        if (M - c[i].X <= c[i].S || c[i].Y <= c[i].S) g[0].push_back(i);
    for (int i = 1; i <= K; ++i)
        if (c[i].X <= c[i].S || N - c[i].Y <= c[i].S) g[i].push_back(K + 1);
    bfs();
    if (vis[K + 1])
        cout << "N\n";
    else
        cout << "S\n";

    return 0;
}