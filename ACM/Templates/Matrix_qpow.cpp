#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;

struct Mat {
    int row, col;
    ll a[15][15];
    Mat(int row, int col) : row(row), col(col) { memset(a, 0, sizeof(a)); }
};

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
    while (b > 0) {
        if (b & 1) t = mul(t, a);
        b >>= 1;
        a = mul(a, a);
    }
    return t;
}