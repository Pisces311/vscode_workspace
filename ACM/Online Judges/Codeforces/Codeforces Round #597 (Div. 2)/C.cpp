#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

char s[maxn];
int dp[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> (s + 1);
    int len = strlen(s + 1);
    dp[0] = 1;
    for (int i = 1; i <= len; ++i) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << "0\n";
            return 0;
        }
        if (s[i] == 'u' && s[i - 1] == 'u')
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        else if (s[i] == 'n' && s[i - 1] == 'n')
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[len] << '\n';

    return 0;
}