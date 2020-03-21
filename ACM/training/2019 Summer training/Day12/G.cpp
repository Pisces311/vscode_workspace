#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct source {
    int a, t;
    bool operator<(const source& b) const { return a > b.a; }
} s[maxn];

int n;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &s[i].a, &s[i].t);
    }
    int v = 0;
    double area1 = 0, area2 = 0;
    for (int i = 1; i <= n; ++i) {
        area1 += 1.0 * (v + v + s[i].a * s[i].t) * s[i].t / 2;
        v = v + s[i].a * s[i].t;
    }
    sort(s + 1, s + n + 1);
    v = 0;
    for (int i = 1; i <= n; ++i) {
        area2 += 1.0 * (v + v + s[i].a * s[i].t) * s[i].t / 2;
        v = v + s[i].a * s[i].t;
    }
    printf("%.1f\n", area2 - area1);

    return 0;
}