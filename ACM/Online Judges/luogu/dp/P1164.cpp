#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const int maxm = 1e2 + 5;

int N, M;
int c[maxn], dp[maxm];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> c[i];
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= c[i]; --j) {
            dp[j] += dp[j - c[i]];
        }
    }
    cout << dp[M] << '\n';

    return 0;
}