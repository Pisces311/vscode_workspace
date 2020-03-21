#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;

ll x0, x1, a, b, mod;
char n[maxn];

struct Mat {
    ll a[2][2];
    Mat(ll x0 = 0, ll x1 = 0, ll x2 = 0, ll x3 = 0) {
        a[0][0] = x0;
        a[0][1] = x1;
        a[1][0] = x2;
        a[1][1] = x3;
    }
    Mat operator*(const Mat& A) const {
        Mat ans;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++)
                    ans.a[i][j] += a[i][k] * A.a[k][j] % mod;
                ans.a[i][j] %= mod;
            }

        return ans;
    }
};

inline Mat qpow(Mat A, int b) {
    Mat ans(1, 0, 0, 1);
    for (; b; b >>= 1, A = A * A) {
        if (b & 1) ans = ans * A;
    }
    return ans;
}

Mat qpow(Mat A, char* b, int len) {
    Mat ans(1, 0, 0, 1);
    for (int i = len; i; i--) {
        int cnt = b[i] - '0';
        ans = ans * qpow(A, cnt);
        A = qpow(A, 10);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x0 >> x1 >> a >> b;
    cin >> (n + 1) >> mod;
    int len = strlen(n + 1);
    n[len]--;
    for (int i = len; n[i] < '0' && i; i--) n[i - 1]--, n[i] += 10;
    Mat A(a, b, 1, 0);
    A = qpow(A, n, len);
    ll ans = (A.a[0][0] * x1 % mod + A.a[0][1] * x0 % mod) % mod;
    cout << ans << '\n';

    return 0;
}