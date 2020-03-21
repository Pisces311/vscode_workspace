#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int maxk = 1e5 + 5;

int n, m, k;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char g[maxn][maxn];
int vis[maxn][maxn];
int ans[maxk];

struct node {
    int x, y;
};

int bfs(int x, int y, int tar) {
    int cnt = 0;
    queue<node> q;
    q.push({x, y});
    vis[x][y] = tar;
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        for (int i = 0; i <= 3; ++i) {
            int xx = f.x + dx[i], yy = f.y + dy[i];
            if (vis[xx][yy] == tar) continue;
            if (g[xx][yy] == '*') {
                ++cnt;
                continue;
            }
            q.push({xx, yy});
            vis[xx][yy] = tar;
        }
    }
    ans[tar] = cnt;
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", g[i] + 1);
    }
    while (k--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (!vis[u][v])
            printf("%d\n", bfs(u, v, k + 1));
        else
            printf("%d\n", ans[vis[u][v]]);
    }

    return 0;
}