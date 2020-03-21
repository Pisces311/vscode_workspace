#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int N, M;
int g[maxn][12], vol[12];
int match[12][maxn], vis[12];
int cur[12], own[12][maxn];

bool line(int u) {
    up(i, 1, M) {
        if (!g[u][i] || vis[i]) continue;
        vis[i] = 1;
        if (cur[i] < vol[i]) {
            own[i][++cur[i]] = u;
            return true;
        } else {
            up(j, 1, cur[i]) if (line(own[i][j])) {
                own[i][cur[i]] = u;
                return true;
            }
        }
    }
    return false;
}

bool hungary() {
    mem(cur, 0);
    up(i, 1, N) {
        mem(vis, 0);
        if (!line(i)) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        up(i, 1, N) up(j, 1, M) scanf("%d", &g[i][j]);
        up(i, 1, M) scanf("%d", &vol[i]);
        if (hungary())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}