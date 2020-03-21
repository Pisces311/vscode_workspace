#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int k, top;
ll l, r, ans;
ll a[20], dp[20][1500], dp2[20][1500], res[20][1500];

inline void init() {
    top = ans = 0;
    mem(dp, -1);
}

ll dfs(int pos, int state, int limit, int lead) {
    if (pos == 0 && state == 1 && lead) return 1;
    if (state == 0 && pos != 0) return 0;
    if (pos == 0) {
        if (state == 0)
            return 1;
        else
            return 0;
    }
    if (!limit && !lead && dp[pos][state] != -1) {
        res[pos][state] = dp2[pos][state];
        return dp[pos][state];
    }
    ll ans = 0;
    int down = 0, up = limit ? a[pos] : 9;
    if (lead) {
        down = 1;
        ans = (ans + dfs(pos - 1, state, 0, 1)) % mod;
        res[pos][state] = res[pos - 1][state];
    } else
        res[pos][state] = 0;
    up(i, down, up) {
        if (state & (1 << i)) {
            ll t1 = dfs(pos - 1, state, limit && i == a[pos], lead && i == 0);
            ll t2 = dfs(pos - 1, state ^ (1 << i), limit && i == a[pos],
                        lead && i == 0);
            ans = (ans + t1 + t2) % mod;
            ll t = (t1 + t2) % mod * i % mod;
            up(j, 1, pos - 1) t = t * 10LL % mod;
            res[pos][state] = (res[pos][state] + res[pos - 1][state] +
                               res[pos - 1][state ^ (1 << i)] + t) %
                              mod;
        }
    }
    if (!limit && !lead) {
        dp[pos][state] = ans;
        dp2[pos][state] = res[pos][state];
    }
    return ans;
}

ll solve(ll x) {
    init();
    if (x == 0) return 0;
    while (x) {
        a[++top] = x % 10;
        x /= 10;
    }
    up(i, 1, (1 << 10) - 1) {
        int t = 0;
        up(j, 0, 9) if (i & (1 << j)) ++t;
        if (t <= k) {
            dfs(top, i, 1, 1);
            ans = (ans + res[top][i]) % mod;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> l >> r >> k;
    cout << (solve(r) - solve(l - 1) + mod) % mod << endl;

    return 0;
}