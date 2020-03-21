#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 3e1 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int l, r, c, w;
} S, E;

int L, R, C;
char g[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

inline void init() { memset(vis, false, sizeof(vis)); }

inline bool check(int l, int r, int c) {
    if (1 <= l && l <= L)
        if (1 <= r && r <= R)
            if (1 <= c && c <= C) return true;
    return false;
}

bool bfs() {
    queue<node> q;
    q.push(S);
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (t.l == E.l && t.r == E.r && t.c == E.c) {
            printf("Escaped in %d minute(s).\n", t.w);
            return true;
        }
        if (vis[t.l][t.r][t.c]) continue;
        vis[t.l][t.r][t.c] = true;
        for (int i = 0; i <= 5; ++i) {
            int l = t.l + dx[i], r = t.r + dy[i], c = t.c + dz[i];
            if (g[l][r][c] != '#' && check(l, r, c)) q.push({l, r, c, t.w + 1});
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &L, &R, &C)) {
        if (L + R + C == 0) break;
        init();
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= R; ++j) {
                scanf("%s", g[i][j] + 1);
            }
        }
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= R; ++j) {
                for (int k = 1; k <= C; ++k) {
                    if (g[i][j][k] == 'S') S = {i, j, k, 0};
                    if (g[i][j][k] == 'E') E = {i, j, k, 0};
                }
            }
        }
        if (!bfs()) printf("Trapped!\n");
    }

    return 0;
}