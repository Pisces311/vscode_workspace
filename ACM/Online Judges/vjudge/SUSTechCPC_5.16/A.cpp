#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;
constexpr int inf = 0x3f3f3f3f;

struct grid {
    int x, y;
};

int n, m, t;
char s[maxn][maxn];
int dis[maxn][maxn];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool check(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

inline void bfs() {
    queue<grid> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (check(x, y) && s[i][j] == s[x][y]) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
    }
    while (!q.empty()) {
        grid u = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = u.x + dx[k], y = u.y + dy[k];
            if (check(x, y) && dis[x][y] > dis[u.x][u.y] + 1) {
                dis[x][y] = dis[u.x][u.y] + 1;
                q.push(grid{x, y});
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
    cin.tie(nullptr);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i) cin >> (s[i] + 1);
    memset(dis, inf, sizeof(dis));
    bfs();
    while (t--) {
        int qx, qy;
        ll qt;
        cin >> qx >> qy >> qt;
        if (dis[qx][qy] == inf || qt < dis[qx][qy]) {
            cout << s[qx][qy] << '\n';
        } else {
            qt -= dis[qx][qy];
            ll nowcolor = (1ll * (s[qx][qy] - '0') + qt) % 2;
            cout << nowcolor << '\n';
        }
    }

    return 0;
}