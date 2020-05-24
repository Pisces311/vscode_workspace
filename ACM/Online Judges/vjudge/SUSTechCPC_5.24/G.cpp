#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, k;
double a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        double ans = 0;
        double chance = 1.0 * k / n;
        ans += chance * a[i];
        int j = i + n - 1;
        for (int cnt = 1; j >= i + k; --j, ++cnt) {
            chance = (chance * (n - k - cnt + 1)) / (n - cnt);
            ans += chance * a[j];
        }
        printf("%.6f ", ans);
    }
    puts("");

    return 0;
}