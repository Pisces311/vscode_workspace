#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e2 + 5;
const int inf = 0x3f3f3f3f;

int T, E, F, N;
int p[maxn], w[maxn], dp[10005];

inline void init() {
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &E, &F);
        int V = F - E;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) scanf("%d %d", &p[i], &w[i]);
        for (int i = 1; i <= N; ++i) {
            for (int j = w[i]; j <= V; ++j) {
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        if (dp[V] == inf)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",
                   dp[V]);
    }

    return 0;
}