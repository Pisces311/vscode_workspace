#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;
constexpr double eps = 1e-8;

// p[1]为最下方的点
struct point {
    double x, y;
} p[maxn], conv[maxn];

struct vct {
    point start, end;
};

int n, top = 0;

inline int sign(double a) { return a < -eps ? -1 : a > eps; }
inline double dis(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// 叉积 > 0: a在b顺时针方向
// 叉积 == 0: a和b共线
// 叉积 < 0: a在b逆时针方向
double cross_product(vct a, vct b) {
    return (a.end.x - a.start.x) * (b.end.y - b.start.y) -
           (b.end.x - b.start.x) * (a.end.y - a.start.y);
}

bool cmp(point p1, point p2) {
    double product = cross_product({p[1], p1}, {p[1], p2});
    return product == 0 ? dis(p[1], p1) < dis(p[1], p2) : product > 0;
}

void Graham() {
    for (int i = 1; i <= n; ++i)
        if (p[i].y < p[1].y) swap(p[1], p[i]);
    sort(p + 2, p + n + 1, cmp);
    conv[++top] = p[1];
    for (int i = 2; i <= n; ++i) {
        vct v1 = {conv[top - 1], conv[top]}, v2 = {conv[top], p[i]};
        while (top > 1 && sign(cross_product(v1, v2)) <= 0) --top;
        conv[++top] = p[i];
    }
    conv[++top] = p[1];
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

double polygon_perimeter() {
    double perimeter = 0;
    for (int i = 1; i < top; ++i) perimeter += dis(conv[i], conv[i + 1]);
    return perimeter;
}

bool inside(point x) {
    for (int i = 1; i < top; ++i)
        if (cross_product({x, conv[i]}, {x, conv[i + 1]}) <= eps) return false;
    return true;
}