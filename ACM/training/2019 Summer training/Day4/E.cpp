#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
int a[maxn], dp[maxn];
vector<int> factor;

inline void init() {
    mem(dp, 0);
    dp[0] = 1;
}

void updataDp(int i) {
    factor.clear();
    up(j, 1, sqrt(a[i])) {
        if (a[i] % j == 0) {
            factor.push_back(j);
            if (a[i] / j != j && a[i] / j <= i) factor.push_back(a[i] / j);
        }
    }
    sort(factor.begin(), factor.end());
    reverse(factor.begin(), factor.end());
    for (auto j : factor) dp[j] = (dp[j] + dp[j - 1]) % mod;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n) scanf("%d", &a[i]);
    init();
    up(i, 1, n) updataDp(i);
    int res = 0;
    up(i, 1, n) res = res % mod + dp[i];
    printf("%d\n", res % mod);

    return 0;
}