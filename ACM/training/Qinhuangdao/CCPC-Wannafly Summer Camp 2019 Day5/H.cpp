#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const double Pi = acos(-1.0);

double R, r, H, F, S;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    double ans, d, ri, h;
    while (~scanf("%lf %lf %lf %lf %lf", &R, &r, &H, &F, &S)) {
        ans = 0;
        ri = r;
        h = H / F;
        S /= 2 * h;
        for (int i = 0; i < F; ++i) {
            d = atan(S / ri);
            int tmp = Pi / d;
            ans += tmp * ri * tan(Pi / tmp) * 2.0;
            ri += (R - r) / F;
        }
        printf("%.3f\n", ans * h);
    }

    return 0;
}