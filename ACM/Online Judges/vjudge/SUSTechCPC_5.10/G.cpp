#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 1e9 + 7;

struct Mat {
    int row, col;
    ll a[3][3];
    Mat(int row, int col) : row(row), col(col) { memset(a, 0, sizeof(a)); }
};

int a, b, n;

Mat mul(const Mat& a, const Mat& b) {
    Mat ans(a.row, b.col);
    for (int i = 1; i <= ans.row; ++i) {
        for (int j = 1; j <= ans.col; ++j) {
            ans.a[i][j] = 0;
            for (int k = 1; k <= a.col; ++k) {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod - 1;
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

ll qpow(ll a, ll b) {
    if (!a) return 0;
    ll ret = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> a >> b >> n) {
        if (n == 0) {
            cout << a << '\n';
            continue;
        } else if (n == 1) {
            cout << b << '\n';
            continue;
        }
        Mat x(2, 2), y(2, 1);
        x.a[1][1] = x.a[1][2] = x.a[2][1] = 1;
        y.a[1][1] = y.a[2][1] = 1;
        Mat ans = mul(qpow(x, n - 2), y);
        cout << qpow(b, ans.a[1][1]) * qpow(a, ans.a[2][1]) % mod << '\n';
    }

    return 0;
}