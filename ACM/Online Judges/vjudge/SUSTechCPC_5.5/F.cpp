#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

int m, n, q, a, b;
ll h[maxn][maxn];
ll sum[maxn][maxn], square[maxn][maxn];
int Max[maxn][maxn][9][9];

void init() {
    for (int row = 1; row <= n; row++)
        for (int col = 1; col <= m; col++) Max[row][col][0][0] = h[row][col];
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

// 左上， 右下
int qmax(int x1, int y1, int x2, int y2) {
    int kx = log(double(x2 - x1 + 1)) / log(2.0);
    int ky = log(double(y2 - y1 + 1)) / log(2.0);
    int m1 = Max[x1][y1][kx][ky];
    int m2 = Max[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = Max[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = Max[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
    return max({m1, m2, m3, m4});
}

inline void init2() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + h[i][j];
}

inline void init3() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            square[i][j] = square[i - 1][j] + square[i][j - 1] -
                           square[i - 1][j - 1] + h[i][j] * h[i][j];
}

//点1左上，点2右下
inline ll query(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] -
           sum[x2][y1 - 1];
}

inline ll query_square(int x1, int y1, int x2, int y2) {
    return square[x2][y2] + square[x1 - 1][y1 - 1] - square[x1 - 1][y2] -
           square[x2][y1 - 1];
}

void solve() {
    double ans = DBL_MAX;
    pair<int, int> id;
    for (int i = 1; i + a - 1 <= n; ++i) {
        for (int j = 1; j + b - 1 <= m; ++j) {
            int tallest = qmax(i, j, i + a - 1, j + b - 1);
            ll total = query(i, j, i + a - 1, j + b - 1) - tallest;
            ll total_square =
                query_square(i, j, i + a - 1, j + b - 1) - tallest * tallest;
            double mean = 1.0 * total / (a * b - 1);
            double var =
                1.0 *
                (total_square + mean * mean * (a * b - 1) - 2 * total * mean) /
                (a * b - 1);
            if (ans > var) {
                ans = var;
                id = make_pair(i, j);
            }
        }
    }
    printf("(%d, %d), %.2f\n", id.first, id.second, ans);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int cas = 0;
    while (~scanf("%d %d", &n, &m)) {
        printf("Case %d:\n", ++cas);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) scanf("%d", &h[i][j]);
        init();
        init2();
        init3();
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &a, &b);
            solve();
        }
    }

    return 0;
}