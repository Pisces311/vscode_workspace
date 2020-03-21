#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 5;

int n, V;
int c[maxn], w[maxn], dp[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i] >> w[i];
    for (int i = 1; i <= n; ++i) w[i] *= c[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    cout << *max_element(dp, dp + V + 1) << '\n';

    return 0;
}