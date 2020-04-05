#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

int n, m;
int val[301][301];
int Max[maxn][maxn][9][9], Min[maxn][maxn][9][9];

void init() {
    for (int row = 1; row <= n; row++)
        for (int col = 1; col <= m; col++)
            Min[row][col][0][0] = Max[row][col][0][0] = val[row][col];
    int lgn = log(double(n)) / log(2.0);
    int lgm = log(double(m)) / log(2.0);
    for (int i = 0; i <= lgn; i++)
        for (int j = 0; j <= lgm; j++) {
            if (i == 0 && j == 0) continue;
            for (int row = 1; row + (1 << i) - 1 <= n; row++)
                for (int col = 1; col + (1 << j) - 1 <= m; col++) {
                    if (i == 0) {
                        Min[row][col][i][j] =
                            min(Min[row][col][i][j - 1],
                                Min[row][col + (1 << (j - 1))][i][j - 1]);
                        Max[row][col][i][j] =
                            max(Max[row][col][i][j - 1],
                                Max[row][col + (1 << (j - 1))][i][j - 1]);
                    } else {
                        Min[row][col][i][j] =
                            min(Min[row][col][i - 1][j],
                                Min[row + (1 << (i - 1))][col][i - 1][j]);
                        Max[row][col][i][j] =
                            max(Max[row][col][i - 1][j],
                                Max[row + (1 << (i - 1))][col][i - 1][j]);
                    }
                }
        }
}

// 左上， 右下
int qmin(int x1, int y1, int x2, int y2) {
    int kx = log(double(x2 - x1 + 1)) / log(2.0);
    int ky = log(double(y2 - y1 + 1)) / log(2.0);
    int m1 = Min[x1][y1][kx][ky];
    int m2 = Min[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = Min[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = Min[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
    return min({m1, m2, m3, m4});
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