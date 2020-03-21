#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
char ch[4];
int card[maxn], line[1200];
double dp[1200];

inline void init() {
    memset(line, 0, sizeof(line));
    memset(dp, 0, sizeof(dp));
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &m)) {
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%s", ch);
            if (ch[0] == 'A')
                card[i] = 11;
            else if (ch[0] == 'J' || ch[0] == 'Q' || ch[0] == 'K' ||
                     ch[1] == '0')
                card[i] = 10;
            else
                card[i] = ch[0] - '0';
        }
        line[m] = card[1];
        for (int i = 2; i <= n; ++i) {
            m += card[i - 1];
            line[m] = card[i];
        }
        dp[m] = 1;
        for (int i = m; i >= 1; --i) {
            if (line[i] == 0) {
                for (int j = 2; j <= 11; ++j) {
                    int mul = j == 10 ? 4 : 1;
                    dp[i] += mul * dp[i + j] / 13;
                }
            } else
                dp[i] = 1;
        }
        double ans = 0;
        for (int i = 1; i <= 10; ++i) {
            ans += dp[i] / 10;
        }
        printf("%.9f\n", ans);
    }

    return 0;
}