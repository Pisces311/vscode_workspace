#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int x, y;
} S, T;

int t, n, m;
char g[maxn][maxn];
int dis[maxn][maxn], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline void init() { memset(dis, inf, sizeof(dis)); }

node find(char ch) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j] == ch) return {i, j};
    return {-1, -1};
}

node transfer(node P) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j] == 'P' && (i != P.x || j != P.y)) return {i, j};
    return {-1, -1};
}

bool check(node P) {
    if (1 <= P.x && P.x <= n && 1 <= P.y && P.y <= m && g[P.x][P.y] != '#')
        return true;
    else
        return false;
}

void bfs(node S) {
    queue<node> q;
    q.push(S);
    dis[S.x][S.y] = 0;
    while (q.size()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i <= 3; ++i) {
            node v = {u.x + dx[i], u.y + dy[i]};
            if (!check(v)) continue;
            if (dis[v.x][v.y] > dis[u.x][u.y] + 1) {
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                if (g[v.x][v.y] == 'P') {
                    v = transfer(v);
                    dis[v.x][v.y] = dis[u.x][u.y] + 1;
                }
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

    cin >> t;
    while (t--) {
        init();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> (g[i] + 1);
        S = find('S'), T = find('T');
        bfs(S);
        cout << dis[T.x][T.y] << '\n';
    }

    return 0;
}