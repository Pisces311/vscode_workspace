#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

int n, m, q, x1, x2, Y1, y2;
int val[301][301];
int Max[maxn][maxn][9][9];

void init() {
    for (int row = 1; row <= n; row++)
        for (int col = 1; col <= m; col++) Max[row][col][0][0] = val[row][col];
    int lgn = log(double(n)) / log(2.0);
    int lgm = log(double(m)) / log(2.0);
    for (int i = 0; i <= lgn; i++)
        for (int j = 0; j <= lgm; j++) {
            if (i == 0 && j == 0) continue;
            for (int row = 1; row + (1 << i) - 1 <= n; row++)
                for (int col = 1; col + (1 << j) - 1 <= m; col++) {
                    if (i == 0) {
                        Max[row][col][i][j] =
                            max(Max[row][col][i][j - 1],
                                Max[row][col + (1 << (j - 1))][i][j - 1]);
                    } else {
                        Max[row][col][i][j] =
                            max(Max[row][col][i - 1][j],
                                Max[row + (1 << (i - 1))][col][i - 1][j]);
                    }
                }
        }
}

int qmax(int x1, int y1, int x2, int y2) {
    int kx = log(double(x2 - x1 + 1)) / log(2.0);
    int ky = log(double(y2 - y1 + 1)) / log(2.0);
    int m1 = Max[x1][y1][kx][ky];
    int m2 = Max[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = Max[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = Max[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
    return max({m1, m2, m3, m4});
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cin >> val[i][j];
        init();
        cin >> q;
        while (q--) {
            cin >> x1 >> Y1 >> x2 >> y2;
            int ret = qmax(x1, Y1, x2, y2);
            cout << ret << ' ';
            if (ret == val[x1][Y1] || ret == val[x1][y2] ||
                ret == val[x2][Y1] || ret == val[x2][y2])
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}