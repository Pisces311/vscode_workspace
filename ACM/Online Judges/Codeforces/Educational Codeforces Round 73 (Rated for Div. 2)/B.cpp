#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

struct node {
    int x, y;
    char ch;
};

int n;
char g[maxn][maxn];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1}, dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool check(int r, int c) {
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    else
        return false;
}

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y, 'W'});
    g[x][y] == 'W';
    while (q.size()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int r = u.x + dx[i], c = u.y + dy[i];
            if (!check(r, c)) continue;
            if (g[r][c] != 'W' && g[r][c] != 'B') {
                char t = (u.ch == 'W' ? 'B' : 'W');
                g[r][c] = t;
                q.push({r, c, t});
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

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) g[i][j] = '#';
    bfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == '#') g[i][j] = 'B';
            cout << g[i][j];
        }
        cout << '\n';
    }

    return 0;
}