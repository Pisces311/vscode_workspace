#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, k;
int sum[maxn], dp[maxn];

struct task {
    int st, ed;
    bool operator<(const task& a) const { return st > a.st; }
} t[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> t[i].st >> t[i].ed;
        sum[t[i].st]++;
    }
    sort(t + 1, t + k + 1);
    int num = 1;
    for (int i = n; i >= 1; --i) {
        if (sum[i])
            for (int j = 1; j <= sum[i]; ++j) {
                dp[i] = max(dp[i], dp[i + t[num].ed]);
                ++num;
            }
        else
            dp[i] = dp[i + 1] + 1;
    }
    cout << dp[1] << '\n';

    return 0;
}