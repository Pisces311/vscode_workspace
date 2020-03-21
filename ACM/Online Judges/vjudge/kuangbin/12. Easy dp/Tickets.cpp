#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;

int N, K;
int t[maxn], adj[maxn], dp[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        memset(dp, inf, sizeof(dp));
        for (int i = 1; i <= K; ++i) scanf("%d", &t[i]);
        for (int i = 1; i < K; ++i) scanf("%d", &adj[i]);
        dp[0] = 0;
        dp[1] = t[1];
        for (int i = 2; i <= K; ++i) {
            dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + adj[i - 1]);
        }
        int h = dp[K] / 3600 + 8;
        dp[K] %= 3600;
        int m = dp[K] / 60;
        dp[K] %= 60;
        printf("%02d:%02d:%02d am\n", h, m, dp[K]);
    }

    return 0;
}