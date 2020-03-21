#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mod = 998244353;

int w, h;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &w, &h);
    ll ans = 1;
    for (int i = 1; i <= w + h; ++i) ans = (ans * 2) % mod;
    printf("%lld\n", ans);

    return 0;
}