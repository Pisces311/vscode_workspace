#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const double eps = 1e-3;
const double start = 1000;
const double rate = 0.98;

struct point {
    double x, y, z;
} p[maxn];

int N;

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

double solve() {
    double T = start;
    point init = {0, 0, 0};
    double ans = 1e18;
    while (T > eps) {
        point far = p[1];
        for (int i = 2; i <= N; i++)
            if (dist(init, p[i]) > dist(init, far)) far = p[i];
        ans = min(ans, dist(init, far));
        init.x += (far.x - init.x) * (T / start);
        init.y += (far.y - init.y) * (T / start);
        init.z += (far.z - init.z) * (T / start);
        T *= rate;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
    printf("%.8f", solve());

    return 0;
}