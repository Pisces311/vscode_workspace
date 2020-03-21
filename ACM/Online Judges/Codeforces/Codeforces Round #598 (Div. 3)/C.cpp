#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int n, m, d;
int c[maxn], sum[maxn], s[maxn], ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) cin >> c[i];
    for (int i = m; i >= 1; --i) sum[i] = sum[i + 1] + c[i];
    int cur = 0;
    for (int i = 1; i <= m; ++i) {
        s[i] = cur + d;
        if (s[i] + sum[i] - 1 > n)
            s[i] = max(cur + 1, s[i] - (s[i] + sum[i] - 1 - n));
        cur = s[i] + c[i] - 1;
    }
    if (n - cur + 1 > d) {
        cout << "NO\n";
        return 0;
    } else
        cout << "YES\n";
    for (int i = 1, j = 1; i <= n && j <= m; ++i) {
        if (i < s[j])
            ans[i] = 0;
        else if (i < s[j] + c[j])
            ans[i] = j;
        else {
            ++j;
            --i;
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}