#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct mouse {
    int w, s, id;
    bool operator<(const mouse& a) const { return w < a.w; }
} m[maxn];

int w, s, n = 0;
int dp[maxn], pre[maxn];

void output(int x) {
    if (pre[x]) output(pre[x]);
    printf("%d\n", m[x].id);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &w, &s)) {
        m[++n] = {w, s, n};
    }
    sort(m + 1, m + n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = i; j >= 1; --j) {
            if (m[i].s < m[j].s && m[i].w > m[j].w) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    int pos = max_element(dp + 1, dp + n + 1) - dp;
    printf("%d\n", dp[pos]);
    output(pos);

    return 0;
}