#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n, k;
int h[maxn];
double g[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
    for (int i = 1; i <= k; ++i) scanf("%lf", &g[i]);

    return 0;
}