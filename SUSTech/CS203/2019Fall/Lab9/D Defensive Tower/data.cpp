#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int T, n, m;
int g[maxn][maxn];
bool vis[maxn];

int random(int a, int b) { return (rand() % (b - a + 1)) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    T = 100;
    cout << T << '\n';
    while (T--) {
        memset(g, 0, sizeof(g));
        memset(vis, false, sizeof(vis));
        n = random(50, 100), m = random(200, 250);
        for (int i = 1; i <= m; ++i) {
            int u = random(1, n), v = random(1, n);
            if (u != v && g[u][v] == 0)
                g[u][v] = g[v][u] = 1;
            else
                --i;
        }
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; ++v)
                if (g[u][v]) {
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
        }
        bool connected = true;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) connected = false;
        if (!connected)
            ++T;
        else {
            cout << n << ' ' << m << '\n';
            for (int i = 1; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (g[i][j]) cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}

/*
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*/