#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e3 + 5;
constexpr int mod = 998244353;

char S[maxn], T[maxn];
ll dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> (S + 1) >> (T + 1);
    int n = strlen(S + 1);
    int m = strlen(T + 1);
    for (int i = 1; i < maxn; ++i) dp[i][i - 1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int l = 1, r = l + i - 1; r <= n; l++, r++) {
            if (l > m || S[i] == T[l])
                dp[l][r] = (dp[l][r] + dp[l + 1][r]) % mod;
            if (r > m || S[i] == T[r])
                dp[l][r] = (dp[l][r] + dp[l][r - 1]) % mod;
        }
    ll ans = 0;
    for (int i = m; i <= n; i++) ans = (ans + dp[1][i]) % mod;
    cout << ans << '\n';

    return 0;
}