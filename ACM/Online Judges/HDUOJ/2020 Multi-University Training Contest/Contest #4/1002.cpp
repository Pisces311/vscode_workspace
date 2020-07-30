#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int T, n;
int A[maxn], D[maxn];
double ans[maxn];

int get_time(int i) {
    int health = 100 - A[i];
    int round = ceil(1.0 * health / A[i]) + 0.5;
    return round * D[i];
}

double beat(int i, int j) {
    int ti = get_time(i), tj = get_time(j);
    if (ti < tj)
        return 1;
    else if (ti == tj)
        return 0.5;
    else
        return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d %d", &A[i], &D[i]);
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            for (int j = 1; j <= n; ++j) {
                ans[i] += beat(i, j);
            }
        }
        printf("%.6f\n", *max_element(ans + 1, ans + n + 1) / n);
    }

    return 0;
}