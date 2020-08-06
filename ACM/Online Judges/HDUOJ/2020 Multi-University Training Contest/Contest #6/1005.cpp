#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e3 + 5;

int t, N;
string cur;
int ans[maxn], ne[13][4];
set<int> dp[13][13];

void merge(set<int>& a, set<int>& b, set<int>& c) {
    for (int i : b) {
        for (int j : c) {
            ll x = i + j, y = i * j;
            if (x <= 5000) a.insert(x);
            if (y <= 5000) a.insert(y);
        }
    }
}

void range(int n, int num) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) dp[i][j].clear();
        dp[i][i].insert(cur[i] - '0');
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k) {
                merge(dp[l][r], dp[l][k], dp[k + 1][r]);
            }
            if (len <= 4) dp[l][r].insert(ne[l][len - 1]);
        }
    }
    for (int i : dp[1][n]) ans[i] = min(ans[i], num);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cur = "01145141919114514";
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 1; i <= 11; ++i) {
        ne[i][0] = cur[i] - '0';
        ne[i][1] = ne[i][0] * 10 + cur[i + 1] - '0';
        ne[i][2] = ne[i][1] * 10 + cur[i + 2] - '0';
        ne[i][3] = ne[i][2] * 10 + cur[i + 3] - '0';
    }
    for (int i = 1; i <= 11; ++i) range(i, i);
    ans[3] = ans[7] = -1;
    cin >> t;
    while (t--) {
        cin >> N;
        cout << ans[N] << '\n';
    }

    return 0;
}