#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;

int n, k;
int val[maxn], dif[maxn];
ll ans = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 1; i <= n - 1; ++i) dif[i] = val[i + 1] - val[i];
    sort(dif + 1, dif + n);
    for (int i = 1; i <= n - k; ++i) ans += dif[i];
    printf("%lld\n", ans);

    return 0;
}