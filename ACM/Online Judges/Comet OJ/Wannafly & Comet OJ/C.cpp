#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, mod;

int cal(int x) {
    int res = 1;
    for (int i = x; i >= 1; --i) res = 1ll * res * i % mod;
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &mod);
    if (n >= 4)
        puts("0");
    else if (n == 1 || n == 2)
        printf("%lld\n", n % mod);
    else if (n == 0)
        printf("%lld\n", 1 % mod);
    else {
        int ans = cal(720);
        printf("%d\n", ans % mod);
    }

    return 0;
}