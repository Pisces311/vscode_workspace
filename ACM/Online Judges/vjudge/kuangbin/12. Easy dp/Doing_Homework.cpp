#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = (1 << 15) + 5;
const int inf = 0x3f3f3f3f;

struct course {
    char name[105];
    int ddl, cost;
} a[20];

int T, N;
int dp[maxn], pre[maxn], t[maxn];

void output(int x) {
    if (pre[x]) output(pre[x]);
    int cur = x - pre[x], id;
    for (int i = N - 1; i >= 0; --i) {
        if (cur == 1 << i) {
            id = i;
            break;
        }
    }
    printf("%s\n", a[id].name);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%s %d %d", a[i].name, &a[i].ddl, &a[i].cost);
        int bit = 1 << N;
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < bit; ++i) {
            for (int j = 0; j <= N - 1; ++j) {
                int tmp = 1 << j;
                if ((i & tmp) == 0) continue;
                int score = t[i - tmp] + a[j].cost - a[j].ddl;
                score = max(0, score);
                if (dp[i] >= dp[i - tmp] + score) {
                    dp[i] = dp[i - tmp] + score;
                    t[i] = t[i - tmp] + a[j].cost;
                    pre[i] = i - tmp;
                }
            }
        }
        printf("%d\n", dp[bit - 1]);
        output(bit - 1);
    }

    return 0;
}