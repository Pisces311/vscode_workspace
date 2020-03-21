#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

struct node {
    int x, y, w;
};

struct pnode {
    int v, w;
    bool operator<(const pnode& a) const { return w > a.w; }
};

int N, x, y, num, ans;
bool vis[110][110], vis0[110];
char g[110][110];
int a[110][110], dis[110][110];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline void init() {
    num = ans = 0;
    mem(dis, 0);
    mem(vis0, false);
    mem(a, 0);
}

inline bool judge(int i, int j) {
    if (vis[i][j] || a[i][j] == -1 || i < 0 || j < 0 || i >= y || j >= x)
        return false;
    return true;
}

void get_new_graph() {
    up(i, 0, y - 1) up(j, 0, x - 1) {
        if (g[i][j] == '#')
            a[i][j] = -1;
        else if (g[i][j] == 'A' || g[i][j] == 'S')
            a[i][j] = ++num;
    }
}

void bfs(int x, int y) {
    mem(vis, false);
    queue<node> q;
    q.push({x, y, 0});
    vis[x][y] = true;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        up(i, 0, 3) {
            int cx = t.x + dx[i], cy = t.y + dy[i], cw = t.w + 1;
            if (judge(cx, cy)) {
                if (a[cx][cy] > 0 && !vis[cx][cy]) dis[a[x][y]][a[cx][cy]] = cw;
                q.push({cx, cy, cw});
            }
            vis[cx][cy] = true;
        }
    }
}

void prim() {
    priority_queue<pnode> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        pnode t = pq.top();
        pq.pop();
        if (vis0[t.v]) continue;
        vis0[t.v] = true;
        ans += t.w;
        up(i, 1, num) if (!vis0[i] && i != t.v) pq.push({i, dis[t.v][i]});
    }
    printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    while (N--) {
        scanf("%d %d\n", &x, &y);
        init();
        up(i, 0, y - 1) gets(g[i]);
        get_new_graph();
        up(i, 0, y - 1) up(j, 0, x - 1) if (a[i][j] > 0) bfs(i, j);
        prim();
    }

    return 0;
}