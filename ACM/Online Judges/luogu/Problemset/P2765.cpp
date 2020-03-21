#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int n, N;
bool vis[maxn];          //记录是否已经连边
int cx[maxn], cy[maxn];  //存储左图和右图的连边对象
int edge[maxn][maxn];    // 邻接矩阵

int dfs(int u) {
    for (int v = 1; v <= n; ++v) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = true;
            if (cy[v] == -1 || dfs(cy[v])) {  //若未连边或递归查找可以改连边对象
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

bool ok(int x) {
    int y = sqrt(x);
    return y * y == x;
}

void find(int u) {
    cout << u << ' ';
    if (cx[u] != -1) find(cx[u]);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int sum = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 1; j < i; ++j) {
            if (ok(i + j)) edge[i][j] = 1;
        }
        n = i;
        memset(vis, false, sizeof(vis));
        sum += dfs(i);
        if (n - sum > N) {
            --n;
            cout << n << '\n';
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (cy[i] == -1) {
            find(i);
            cout << '\n';
        }

    return 0;
}