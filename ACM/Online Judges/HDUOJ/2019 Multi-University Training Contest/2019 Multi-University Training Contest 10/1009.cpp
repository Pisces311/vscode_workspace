#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

struct node {
    int x, y;
};

int T, n, m, q;
int g[maxn][maxn];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline void init() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) g[i][j] = 1;
}

bool judge(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m) return true;
    return false;
}

int bfs(node s) {
    int cnt = 0;
    queue<node> q;
    q.push(s);
    g[s.x][s.y] = 0;
    ++cnt;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i <= 3; ++i) {
            int x = u.x + dx[i], y = u.y + dy[i], num = 0;
            if (!judge(x, y) || g[x][y] == 0) continue;
            if (i == 0 || i == 1) {
                int ax = x, ay = y - 1;
                if (ay == 0 || g[ax][ay] == 1) ++num;
                ax = x, ay = y + 1;
                if (ay == m + 1 || g[ax][ay] == 1) ++num;
                if (num != 2) {
                    g[x][y] = 0;
                    ++cnt;
                    q.push({x, y});
                }
            } else {
                int ax = x - 1, ay = y;
                if (ax == 0 || g[ax][ay] == 1) ++num;
                ax = x + 1, ay = y;
                if (ax == n + 1 || g[ax][ay] == 1) ++num;
                if (num != 2) {
                    g[x][y] = 0;
                    ++cnt;
                    q.push({x, y});
                }
            }
        }
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m >> q;
        init();
        while (q--) {
            int x, y;
            cin >> x >> y;
            if (g[x][y] == 0)
                cout << 0 << '\n';
            else
                cout << bfs({x, y}) << '\n';
        }
    }

    return 0;
}