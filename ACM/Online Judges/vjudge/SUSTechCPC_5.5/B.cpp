#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 1e9 + 7;

struct Mat {
    int row, col;
    ll a[15][15];
    Mat(int row, int col) : row(row), col(col) { memset(a, 0, sizeof(a)); }
};

int T;
ll N;

Mat mul(const Mat& a, const Mat& b) {
    Mat ans(a.row, b.col);
    for (int i = 1; i <= ans.row; ++i) {
        for (int j = 1; j <= ans.col; ++j) {
            ans.a[i][j] = 0;
            for (int k = 1; k <= a.col; ++k) {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

Mat qpow(Mat a, ll b) {
    Mat t(a.row, a.col);
    for (int i = 1; i <= t.row; ++i) t.a[i][i] = 1;
    while (b) {
        if (b & 1) t = mul(t, a);
        b >>= 1;
        a = mul(a, a);
    }
    return t;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        Mat ans(9, 9), tmp(9, 9);
        for (int i = 1; i <= 9; ++i) ans.a[1][i] = 1;
        tmp.a[1][4] = tmp.a[1][7] = 1;
        tmp.a[2][1] = tmp.a[2][4] = tmp.a[2][7] = 1;
        tmp.a[3][1] = tmp.a[3][4] = 1;
        tmp.a[4][2] = tmp.a[4][5] = tmp.a[4][8] = 1;
        tmp.a[5][2] = tmp.a[5][8] = 1;
        tmp.a[6][2] = tmp.a[6][5] = 1;
        tmp.a[7][3] = tmp.a[7][9] = 1;
        tmp.a[8][6] = tmp.a[8][9] = 1;
        tmp.a[9][3] = tmp.a[9][6] = 1;
        Mat ret = mul(ans, qpow(tmp, N - 2));
        cout << accumulate(ret.a[1] + 1, ret.a[1] + 10, 0ll) % mod << '\n';
    }

    return 0;
}