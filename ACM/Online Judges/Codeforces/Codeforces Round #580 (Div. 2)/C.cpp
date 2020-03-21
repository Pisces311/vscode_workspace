#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int n;
ll ans[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ll tot = 1ll * (1 + 2 * n) * 2 * n / 2;
    ll sum = tot / 2;
    if (sum * 2 != tot)
        cout << "YES" << '\n';
    else {
        cout << "NO" << '\n';
        return 0;
    }
    bool flag = true;
    for (int i = 1, j = 1; j <= n; ++j, i += 2) {
        if (flag) {
            ans[j] = i;
            ans[j + n] = i + 1;
        } else {
            ans[j + n] = i;
            ans[j] = i + 1;
        }
        flag = !flag;
    }
    for (int i = 1; i <= 2 * n; ++i) cout << ans[i] << " \n"[i == 2 * n];

    return 0;
}