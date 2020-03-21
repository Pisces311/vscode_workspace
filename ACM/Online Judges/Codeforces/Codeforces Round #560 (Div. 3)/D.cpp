#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 305;

int t, n;
ll a[maxn];

inline bool check(ll ans) {
    up(i, 2, (n + 1) / 2) {
        if (a[i] * a[n - i + 1] != ans) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        up(i, 1, n) scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        ll ans = a[1] * a[n];
        if (!check(ans)) {
            printf("-1\n");
            continue;
        }
        int cnt = 0;
        for (ll i = 2; pow(i, 2) <= ans; i++) {
            if (ans % i == 0) cnt += (pow(i, 2) == ans ? 1 : 2);
        }
        printf("%lld\n", cnt == n ? ans : -1);
    }

    return 0;
}