#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 1e9 + 7;

char w[maxn];
ll dp[maxn];

bool check(int x) {
    if (w[x] == 'W' && w[x - 1] == 'N') return true;
    if (w[x] == 'E' && w[x - 1] == 'N') return true;
    if (w[x] == 'E' && w[x - 1] == 'S') return true;
    if (w[x] == 'W' && w[x - 1] == 'S') return true;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> (w + 1);
    int n = strlen(w + 1);
    dp[1] = 1;
    if (check(2))
        dp[2] = 2;
    else
        dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        if (check(i)) {
            dp[i] = dp[i - 2] * 2;
        } else {
            dp[i] = dp[i - 1];
        }
        dp[i] %= mod;
    }
    cout << dp[n] << '\n';

    return 0;
}