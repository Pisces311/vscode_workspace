#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll n, m;

struct Mat {
    ll a[maxn][maxn];
} ans, a;

Mat mul(const Mat& a, const Mat& b) {
    Mat ans;
    up(i, 1, m) {
        up(j, 1, m) {
            ans.a[i][j] = 0;
            up(k, 1, m) {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

Mat quick_pow(Mat a, ll b) {
    Mat t;
    up(i, 1, m) t.a[i][i] = 1;
    while (b) {
        if (b & 1) t = mul(t, a);
        b >>= 1;
        a = mul(a, a);
    }
    return t;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m;
    if (n < m)
        cout << 1 << endl;
    else {
        up(i, 1, m - 1) ans.a[i + 1][i] = 1;
        ans.a[1][m] = ans.a[m][m] = 1;
        ans = quick_pow(ans, n - m);
        up(i, 1, m - 1) a.a[1][i] = 1;
        a.a[1][m] = 2;
        a = mul(a, ans);
        cout << a.a[1][m] << endl;
    }
    return 0;
}