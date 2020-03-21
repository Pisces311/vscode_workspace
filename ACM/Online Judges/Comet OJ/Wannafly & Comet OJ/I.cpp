#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll n, m, k;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%lld %lld %lld", &n, &m, &k);
    if (k <= (n - 1) * (m - 1))
        printf("%lld\n", n + m - 2);
    else
        puts("-1");

    return 0;
}