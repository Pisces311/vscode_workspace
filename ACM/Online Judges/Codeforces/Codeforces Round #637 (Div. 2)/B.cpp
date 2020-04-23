#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n, k;
int a[maxn], peek[maxn], sum[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) peek[i] = sum[i] = 0;
        for (int i = 2; i < n; ++i)
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) peek[i] = 1;
        for (int i = 2; i < k; ++i) sum[1] += peek[i];
        for (int i = k + 1; i <= n; ++i)
            sum[i + 1 - k] = sum[i - k] - peek[i + 1 - k] + peek[i - 1];
        int Max = *max_element(sum + 1, sum + n + 1);
        for (int i = 1; i <= n; ++i)
            if (sum[i] == Max) {
                cout << Max + 1 << ' ' << i << '\n';
                break;
            }
    }

    return 0;
}