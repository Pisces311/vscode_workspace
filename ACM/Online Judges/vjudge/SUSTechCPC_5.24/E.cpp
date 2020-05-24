#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr double eps = 1e-8;

double t[5];
double target;

inline int sign(double a) { return a < -eps ? -1 : a > eps; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%lf %lf %lf %lf", &t[1], &t[2], &t[3], &t[4]);
    scanf("%lf", &target);
    sort(t + 1, t + 5);
    if (sign(t[2] + t[3] + t[4] - 3 * target) <= 0)
        puts("infinite");
    else if (sign(t[1] + t[2] + t[3] - 3 * target) <= 0) {
        printf("%.2f\n", 3 * target - t[2] - t[3]);
    } else
        puts("impossible");

    return 0;
}