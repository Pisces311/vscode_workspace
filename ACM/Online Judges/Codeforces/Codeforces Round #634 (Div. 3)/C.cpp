#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n;
int a[maxn], num[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) num[i] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) ++num[a[i]];
        int Max = *max_element(num + 1, num + n + 1);
        int cnt = -1;
        for (int i = 1; i <= n; ++i)
            if (num[i]) ++cnt;
        if (Max >= cnt + 2)
            cout << cnt + 1 << '\n';
        else
            cout << min(Max, cnt) << '\n';
    }

    return 0;
}