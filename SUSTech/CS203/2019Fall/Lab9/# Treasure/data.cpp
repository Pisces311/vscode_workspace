#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

char g[maxn][maxn];

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int T = 10;
    cout << T << '\n';
    while (T--) {
        int n = rint(500, 1000), m = rint(500, 1000);
        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) g[i][j] = '.';
        int block = rint(n * m / 4, n * m / 2);
        while (block--) {
            int x = rint(1, n), y = rint(1, m);
            g[x][y] = '#';
        }
        int pcnt = 2, scnt = 1, tcnt = 1;
        while (pcnt--) {
            int x = rint(1, n), y = rint(1, m);
            if (g[x][y] != 'P')
                g[x][y] = 'P';
            else
                ++pcnt;
        }
        while (scnt--) {
            int x = rint(1, n), y = rint(1, m);
            if (g[x][y] != 'P')
                g[x][y] = 'S';
            else
                ++scnt;
        }
        while (tcnt--) {
            int x = rint(1, n), y = rint(1, m);
            if (g[x][y] != 'P' && g[x][y] != 'S')
                g[x][y] = 'T';
            else
                ++tcnt;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << g[i][j];
            cout << '\n';
        }
    }

    return 0;
}