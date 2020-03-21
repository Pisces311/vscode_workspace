#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
double n, m;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &T);
    int cas = 0;
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%lf %lf", &n, &m);
        if (n == 1)
            printf("%.6f", n);
        else
            printf("%.6f", 0.5);
        printf(" %.6f\n", (m + 1) / (m * 2));
    }

    return 0;
}