#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e2 + 5;

#define oo 1000000010
const int LOG = 10;
char grid[maxn][maxn];
int val[maxn][maxn], sum[maxn][maxn][4];
int st[maxn][maxn][LOG][LOG], lg[maxn];
int n, q, m, r1, c1, r2, c2, nr, nc;

string S = "RGYB";
int dr[4] = {0, 0, 1, 1};
int dc[4] = {0, 1, 0, 1};

inline bool check(int r1, int c1, int r2, int c2, int k) {
    r1++, c1++, r2++, c2++;
    return ((sum[r2][c2][k] - sum[r1 - 1][c2][k] - sum[r2][c1 - 1][k] +
             sum[r1 - 1][c1 - 1][k]) == (r2 - r1 + 1) * (c2 - c1 + 1));
}

inline bool valid(int r, int c, int s) {
    if (r < 0 || c < 0) return false;
    if (r + (s << 1) - 1 >= n || c + (s << 1) - 1 >= m) return false;
    for (int i = 0; i < 4; i++) {
        nr = r + dr[i] * s;
        nc = c + dc[i] * s;
        if (!check(nr, nc, nr + s - 1, nc + s - 1, i)) return false;
    }
    return true;
}

void build() {
    lg[1] = 0;
    for (int i = 2; i < maxn; i++) {
        lg[i] = lg[i - 1];
        if ((1 << (lg[i] + 1)) == i) lg[i]++;
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            for (int j = 0; j < m; j++) {
                st[i][j][k][0] = max(st[i][j][k - 1][0],
                                     st[i + (1 << (k - 1))][j][k - 1][0]);
            }
        }
    }
    for (int l = 1; l < LOG; l++) {
        for (int k = 0; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                for (int j = 0; j + (1 << l) <= m; j++) {
                    st[i][j][k][l] = max(st[i][j][k][l - 1],
                                         st[i][j + (1 << (l - 1))][k][l - 1]);
                }
            }
        }
    }
}

int a, b;

inline int getmax(int r1, int c1, int r2, int c2) {
    if (r2 < r1 || c2 < c1 || r1 < 0 || r2 >= n || c1 < 0 || c2 >= m)
        return -oo;
    a = lg[(r2 - r1) + 1];
    b = lg[(c2 - c1) + 1];
    return max(max(st[r1][c1][a][b], st[r2 - (1 << a) + 1][c1][a][b]),
               max(st[r1][c2 - (1 << b) + 1][a][b],
                   st[r2 - (1 << a) + 1][c2 - (1 << b) + 1][a][b]));
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    // 处理每种颜色字母的2维前缀和
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                sum[i + 1][j + 1][k] = sum[i][j + 1][k] + sum[i + 1][j][k] -
                                       sum[i][j][k] + (S[k] == grid[i][j]);
            }
        }
    }
    // 对每个cell进行二分
    int l, r, res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            l = 1, r = min(min(i + 1, n - i), min(j + 1, m - j));
            while (r >= l) {
                int mid = (l + r) >> 1;
                // 判断当前cell的颜色作为最右下角的块的正方形边长最大为多少
                if (valid(i - mid + 1, j - mid + 1, mid))
                    st[i][j][0][0] = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
        }
    }
    build();
    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        l = 1, r = (n >> 1), res = 0;
        while (r >= l) {
            int mid = (l + r) >> 1;
            if (getmax(r1 + mid - 1, c1 + mid - 1, r2 - mid, c2 - mid) >= mid)
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << res * res * 4 << '\n';
    }

    return 0;
}