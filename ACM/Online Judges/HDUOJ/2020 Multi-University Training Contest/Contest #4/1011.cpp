#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, a, b, d, t0;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &d, &t0);
        printf("%.6f\n", (double)d);
    }

    return 0;
}