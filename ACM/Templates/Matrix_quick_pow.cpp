#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct Mat {
    ll a[maxn][maxn];
} ans, a;

int n, m;

Mat mul(const Mat& a, const Mat& b) {
    Mat ans;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans.a[i][j] = 0;
            for (int k = 1; k <= m; ++k) {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

Mat quick_pow(Mat a, ll b) {
    Mat t;
    for (int i = 1; i <= m; ++i) t.a[i][i] = 1;
    while (b) {
        if (b & 1) t = mul(t, a);
        b >>= 1;
        a = mul(a, a);
    }
    return t;
}

int main() { return 0; }