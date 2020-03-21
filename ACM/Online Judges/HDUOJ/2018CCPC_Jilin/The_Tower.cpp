#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T;
double r, h;
double x, y, z, vx, vy, vz;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int kas = 1; kas <= T; ++kas) {
        scanf("%lf %lf", &r, &h);
        scanf("%lf %lf %lf", &x, &y, &z);
        scanf("%lf %lf %lf", &vx, &vy, &vz);
        double a = vx * vx * h * h + vy * vy * h * h - vz * vz * r * r;
        double b = 2 * x * vx * h * h + 2 * y * vy * h * h -
                   2 * z * vz * r * r + 2 * r * r * h * vz;
        double c =
            (x * x + y * y - r * r) * h * h - r * r * z * z + 2 * r * r * h * z;
        double r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a),
               r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double ans;
        if (r1 < r2) {
            double dz = z + vz * r1;
            if (dz >= 0 && dz <= h)
                ans = r1;
            else
                ans = r2;
        } else {
            double dz = z + vz * r2;
            if (dz >= 0 && dz <= h)
                ans = r2;
            else
                ans = r1;
        }
        printf("Case %d: %.10f\n", kas, ans);
    }

    return 0;
}