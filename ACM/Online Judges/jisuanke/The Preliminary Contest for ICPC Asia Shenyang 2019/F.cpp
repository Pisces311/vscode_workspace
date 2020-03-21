#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;

struct pool {
    ll val;
    int num;
} p[maxn];

int n;
ll k, sum;
ll a[maxn], b[maxn];
ll pre[maxn], suf[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> k) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sum = accumulate(a + 1, a + n + 1, 0);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) b[i] = a[i];
        int m = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 0; i <= m + 1; ++i) pre[i] = suf[i] = 0;
        for (int i = 1; i <= m; ++i) {
            p[i].val = b[i];
            p[i].num = upper_bound(a + 1, a + n + 1, b[i]) -
                       lower_bound(a + 1, a + n + 1, b[i]);
        }
        int num1 = 0, num2 = 0;
        ll mi = -1, ma = -1;
        p[m + 1].val = 2e10, p[0].val = -2e10;
        for (int i = 1; i <= m; ++i) {
            num1 += p[i].num;
            pre[i] = pre[i - 1] + (p[i + 1].val - p[i].val) * num1;
            if (pre[i] > k) {
                ll ret = k - pre[i - 1];
                mi = p[i].val + ret / num1;
                break;
            }
        }
        for (int j = m; j >= 1; --j) {
            num2 += p[j].num;
            suf[j] = suf[j + 1] + (p[j].val - p[j - 1].val) * num2;
            if (suf[j] > k) {
                ll ret = k - suf[j + 1];
                ma = p[j].val - ret / num2;
                break;
            }
        }
        if (ma > mi)
            cout << ma - mi << '\n';
        else {
            if (sum % n == 0)
                cout << "0\n";
            else
                cout << "1\n";
        }
    }

    return 0;
}