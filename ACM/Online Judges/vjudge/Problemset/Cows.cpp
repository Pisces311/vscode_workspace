#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

// p[1]为最下方的点
struct point {
    double x, y;
} p[maxn], conv[maxn];

struct vct {
    point start, end;
};

int n, top = 0;

// 叉积 > 0: a在b顺时针方向
// 叉积 == 0: a和b共线
// 叉积 < 0: a在b逆时针方向
double cross_product(vct a, vct b) {
    return (a.end.x - a.start.x) * (b.end.y - b.start.y) -
           (b.end.x - b.start.x) * (a.end.y - a.start.y);
}

double dis(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

bool cmp(point p1, point p2) {
    double product = cross_product({p[1], p1}, {p[1], p2});
    return product == 0 ? dis(p[1], p1) < dis(p[1], p2) : product > 0;
}

double polygon_area() {
    if (top < 4) return 0;
    double area = 0;
    point origin = {0, 0};
    for (int i = 1; i < top; ++i)
        area += cross_product({origin, conv[i]}, {origin, conv[i + 1]});
    area = fabs(area / 2.0);
    return area;
}

void Graham() {
    sort(p + 2, p + n + 1, cmp);
    conv[++top] = p[1];
    for (int i = 2; i <= n; ++i) {
        while (top > 1 && cross_product({conv[top - 1], conv[top]},
                                        {conv[top], p[i]}) <= 0)
            --top;
        conv[++top] = p[i];
    }
    conv[++top] = p[1];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        if (p[i].y < p[1].y) swap(p[1], p[i]);
    }
    Graham();
    cout << (int)(polygon_area() / 50) << '\n';

    return 0;
}