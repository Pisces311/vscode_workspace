#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, n, i, j;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    freopen("perechi3.in", "r", stdin);
    freopen("perechi3.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        ll ans = 0, pos = 0;
        for (i = 1; i * i <= n; i++) {
            ans += 2 * (n / i - i) + 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}