#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 3e1 + 5;

int n, ans;
int g[maxn][maxn], ddl[maxn];
int t[maxn];
bool vis[maxn];

inline void init() { ans = INT_MAX; }

inline void floyd() {
    up(k, 1, n) up(i, 1, n) up(j, 1, n) g[i][j] =
        min(g[i][j], g[i][k] + g[k][j]);
}

void dfs(int s, int t, int sum, int cnt) {
    if (cnt == n) {
        ans = min(ans, sum);
        return;
    }
    if (sum + (n - cnt) * t >= ans) return;
    up(i, 2, n) if (!vis[i] && t + g[s][i] > ddl[i]) return;
    up(i, 2, n) if (!vis[i]) {
        vis[i] = true;
        dfs(i, t + g[s][i], sum + t + g[s][i], cnt + 1);
        vis[i] = false;
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    while (~scan(n)) {
        init();
        up(i, 1, n) up(j, 1, n) scan(g[i][j]);
        up(i, 2, n) scan(ddl[i]);
        floyd();
        dfs(1, 0, 0, 1);
        if (ans == INT_MAX)
            print(-1);
        else
            print(ans);
    }

    return 0;
}