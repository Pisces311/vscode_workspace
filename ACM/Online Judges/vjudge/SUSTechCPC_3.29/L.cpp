#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n;
char type[3];
int num[maxn], op[maxn];
double t[maxn], ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%s %lf", type, &t[i]);
        if (type[0] == '-')
            op[i] = -1;
        else
            op[i] = 1;
    }
    for (int i = 1; i <= 2 * n; i++) num[i] = num[i - 1] + op[i];
    for (int i = 2 * n; i >= 1; i--) {
        if (op[i] == -1) {
            double p = 1.0 / num[i - 1];
            ans[i] = p * t[i] + (1 - p) * ans[i + 1];
        } else
            ans[i] = ans[i + 1];
    }
    for (int i = 1; i <= 2 * n; ++i)
        if (op[i] == 1) printf("%.6f\n", ans[i] - t[i]);

    return 0;
}