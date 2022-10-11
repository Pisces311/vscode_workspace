#include <bits/stdc++.h>
using namespace std;

int ST[305][305][9][9];

// 0-based v
void init(const vector<vector<int>>& v) {
    int n = v.size(), m = v[0].size();
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++) ST[r][c][0][0] = v[r - 1][c - 1];
    int lgn = log2(n), lgm = log2(m);
    for (int i = 0; i <= lgn; i++)
        for (int j = 0; j <= lgm; j++) {
            if (!i && !j) continue;
            for (int r = 1; r + (1 << i) - 1 <= n; r++)
                for (int c = 1; c + (1 << j) - 1 <= m; c++) {
                    if (i == 0) {
                        ST[r][c][i][j] =
                            min(ST[r][c][i][j - 1],
                                ST[r][c + (1 << (j - 1))][i][j - 1]);
                    } else {
                        ST[r][c][i][j] =
                            min(ST[r][c][i - 1][j],
                                ST[r + (1 << (i - 1))][c][i - 1][j]);
                    }
                }
        }
}

// top-left, bottom-right
int query(int x1, int y1, int x2, int y2) {
    int lgx = log2(x2 - x1 + 1);
    int lgy = log2(y2 - y1 + 1);
    return min({ST[x1][y1][lgx][lgy], ST[x2 - (1 << lgx) + 1][y1][lgx][lgy],
                ST[x1][y2 - (1 << lgy) + 1][lgx][lgy],
                ST[x2 - (1 << lgx) + 1][y2 - (1 << lgy) + 1][lgx][lgy]});
}