#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
int p[maxn];
char g[105][105];
int dis[105][105];
bool del[maxn];

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> (g[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) dis[i][j] = g[i][j] == '1' ? 1 : inf;
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> p[i];
    floyd();
    int cnt = 0;
    for (int i = 1, j = 2; j < m;) {
        while (j < m &&
               dis[p[i]][p[j]] + dis[p[j]][p[j + 1]] == dis[p[i]][p[j + 1]] &&
               p[i] != p[j + 1]) {
            del[j] = true;
            ++j;
            ++cnt;
        }
        i = j;
        ++j;
    }
    cout << m - cnt << '\n';
    for (int i = 1; i <= m; ++i)
        if (!del[i]) cout << p[i] << " \n"[i == m];

    return 0;
}