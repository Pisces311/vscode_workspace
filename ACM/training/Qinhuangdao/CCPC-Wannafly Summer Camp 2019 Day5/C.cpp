#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const double inf = 0x3f3f3f3f;

double Rm, R, r, x, y, vx, vy;
double ans;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%lf", &Rm)) {
        scanf("%lf %lf %lf %lf %lf %lf", &R, &r, &x, &y, &vx, &vy);
        double delta1 = 4 * (x * vx + y * vy) * (x * vx + y * vy) -
                        4 * (vx * vx + vy * vy) *
                            (x * x + y * y - R * R - 2 * R * r - r * r);
        if (delta1 <= 0.0)
            puts("0");
        else {
            double t1 = (-2 * (x * vx + y * vy) - sqrt(delta1)) *
                        (vx * vx + vy * vy) / 2.0,
                   t2 = (-2 * (x * vx + y * vy) + sqrt(delta1)) *
                        (vx * vx + vy * vy) / 2.0;
            double delta2 = 4 * (x * vx + y * vy) * (x * vx + y * vy) -
                            4 * (vx * vx + vy * vy) *
                                (x * x + y * y - Rm * Rm - 2 * Rm * r - r * r);
            if (t1 < 0.0 || t2 < 0.0) {
                puts("0");
            } else {
                if (delta2 <= 0.0)
                    ans = sqrt(delta1) / (vx * vx + vy * vy);
                else
                    ans = sqrt(delta1) / (vx * vx + vy * vy) -
                          sqrt(delta2) / (vx * vx + vy * vy);
                printf("%.3f\n", ans);
            }
        }
    }

    return 0;
}