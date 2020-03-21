#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int N;
int a[maxn];
ll tmp1, tmp2;
ll dp[maxn][105][2];

inline void init() { tmp1 = tmp2 = 0; }

inline ll get_sum(int pos) {
    ll ret = 0;
    up(i, 1, 100) ret = (ret + dp[pos][i][1]) % mod;
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    up(i, 1, N) cin >> a[i];
    if (a[1] == -1)
        up(i, 1, 100) dp[1][i][0] = 1;
    else
        dp[1][a[1]][0] = 1;
    up(i, 2, N) {
        init();
        tmp1 = get_sum(i - 1);
        up(j, 1, 100) {
            tmp1 = (tmp1 - dp[i - 1][j][1] + mod) % mod;
            tmp2 = (tmp2 + dp[i - 1][j][0]) % mod;
            dp[i][j][0] = (tmp1 + tmp2) % mod;
            dp[i][j][1] = (tmp1 + dp[i - 1][j][0]) % mod;
        }
        if (a[i] != -1)
            up(j, 1, 100) if (j != a[i]) dp[i][j][0] = dp[i][j][1] = 0;
    }
    cout << get_sum(N) << endl;

    return 0;
}