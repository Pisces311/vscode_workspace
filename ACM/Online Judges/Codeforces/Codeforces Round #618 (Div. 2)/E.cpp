#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const double eps = 1e-9;

int n;
double a[maxn], stk[maxn], sum[maxn];
int pre[maxn], top = 0;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lf", &a[i]);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        for (; top; top--) {
            double tmp = (sum[i] - sum[pre[top]]) / (1.0 * i - pre[top]);
            if (tmp - stk[top] > eps) break;
        }
        stk[++top] = (sum[i] - sum[pre[top]]) / (1.0 * i - pre[top]);
        pre[top] = i;
    }
    for (int i = 1; i <= top; ++i)
        for (int j = pre[i - 1] + 1; j <= pre[i]; ++j) a[j] = stk[i];
    for (int i = 1; i <= n; ++i) printf("%.9f\n", a[i]);

    return 0;
}