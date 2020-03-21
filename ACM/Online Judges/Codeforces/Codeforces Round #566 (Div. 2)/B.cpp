#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e2 + 5;

int h, w;
char g[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &h, &w);
    up(i, 1, h) scanf("%s", g[i] + 1);
    bool ok = true;
    int row = -1, col = -1;
    int tot = 0;
    up(i, 1, h) {
        int cnt = 0;
        up(j, 1, w) if (g[i][j] == '*') {
            ++cnt;
            ++tot;
        }
        if (cnt == 2) ok = false;
        if (cnt > 1 && row == -1)
            row = i;
        else if (cnt > 1)
            ok = false;
    }
    up(j, 1, w) {
        int cnt = 0;
        up(i, 1, h) if (g[i][j] == '*')++ cnt;
        if (cnt == 2) ok = false;
        if (cnt > 1 && col == -1)
            col = j;
        else if (cnt > 1)
            ok = false;
    }
    if (row == -1 || col == -1 || row == 1 || row == h || col == 1 || col == w)
        ok = false;
    if (ok) {
        bool ok2 = true;
        int num = 0;
        int x = row, y = col, cur = 0;
        while (x <= h && g[x][y] == '*') {
            ++num;
            ++x;
            ++cur;
        }
        if (cur == 1) ok2 = false;
        x = row, y = col, cur = 0;
        while (x >= 1 && g[x][y] == '*') {
            ++num;
            --x;
            ++cur;
        }
        if (cur == 1) ok2 = false;
        x = row, y = col, cur = 0;
        while (y >= 1 && g[x][y] == '*') {
            ++num;
            --y;
            ++cur;
        }
        if (cur == 1) ok2 = false;
        x = row, y = col, cur = 0;
        while (y <= w && g[x][y] == '*') {
            ++num;
            ++y;
            ++cur;
        }
        if (cur == 1) ok2 = false;
        if (num - 3 != tot) ok2 = false;
        printf(ok2 ? "YES\n" : "NO\n");
    } else
        printf("NO\n");

    return 0;
}