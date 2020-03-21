#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 8e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int x, y;
} S, T;

int t, r, c;
char g[maxn][maxn];
int dis[maxn][maxn];
int dir[][2] = {{4, 0}, {-4, 0}, {-2, 6}, {2, 6}, {-2, -6}, {2, -6}};

inline node find(char ch) {
    for (int i = 0; i < 4 * r + 3; ++i)
        for (int j = 0; j < 6 * c + 3; ++j)
            if (g[i][j] == ch) return {i, j};
    return {-1, -1};
}

inline bool check(node v) {
    if (0 <= v.x && v.x < 4 * r + 3 && 0 <= v.y && v.y < 6 * c + 3) return true;
    return false;
}

void bfs(node S) {
    for (int i = 0; i < 4 * r + 3; ++i)
        for (int j = 0; j < 6 * c + 3; ++j) dis[i][j] = inf;
    queue<node> q;
    q.push(S);
    dis[S.x][S.y] = 0;
    while (q.size()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            node v = {u.x + dir[i][0], u.y + dir[i][1]};
            node path = {u.x + dir[i][0] / 2, u.y + dir[i][1] / 2};
            if (!check(v)) continue;
            if (g[path.x][path.y] != ' ') continue;
            if (dis[v.x][v.y] > dis[u.x][u.y] + 1) {
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
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

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d\n", &r, &c);
        for (int i = 0; i < 4 * r + 3; ++i) gets(g[i]);
        S = find('S'), T = find('T');
        bfs(S);
        printf("%d\n", dis[T.x][T.y] == inf ? -1 : dis[T.x][T.y] + 1);
    }

    return 0;
}