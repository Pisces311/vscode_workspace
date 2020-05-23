#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;
constexpr double eps = 1e-3;

inline int sign(double a) { return a < -eps ? -1 : a > eps; }

struct point {
    double x, y;
    int flag;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    //模长
    double len() { return sqrt(x * x + y * y); }
    //叉积
    double operator^(const point &a) const { return x * a.y - y * a.x; }
    point operator*(double u) const { return point(x * u, y * u); }
    point operator+(const point &a) { return point(x + a.x, y + a.y); }
    point operator-(const point &a) { return point(x - a.x, y - a.y); }
    bool operator==(const point &a) {
        return sign(x - a.x) == 0 && sign(y - a.y) == 0;
    }
};

struct cirles {
    point o;
    double r;
} c[maxn];

struct line {
    point a, b;
};

// 两直线交点
point line_intersection(line l1, line l2) {
    double t = ((l1.a.x - l2.a.x) * (l2.a.y - l2.b.y) -
                (l1.a.y - l2.a.y) * (l2.a.x - l2.b.x)) /
               ((l1.a.x - l1.b.x) * (l2.a.y - l2.b.y) -
                (l1.a.y - l1.b.y) * (l2.a.x - l2.b.x));
    return l1.a + (l1.b - l1.a) * t;
}

// 直线到圆心的距离
double line_circle_distance(line l, cirles a) {
    return fabs((a.o - l.a) ^ (l.b - l.a)) / (l.b - l.a).len();
}

// 直线与圆交点以及个数
int line_circle_intersection(cirles c, line l, point &p1, point &p2) {
    if (line_circle_distance(l, c) > c.r) return 0;
    point pi = c.o;
    pi.x += l.a.y - l.b.y;
    pi.y += l.b.x - l.a.x;
    pi = line_intersection({pi, c.o}, l);
    double t = sqrt(c.r * c.r - (pi - c.o).len() * (pi - c.o).len()) /
               (l.a - l.b).len();
    p1 = pi - (l.b - l.a) * t;
    p2 = pi + (l.b - l.a) * t;
    return 1 + !(p1 == p2);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    line l;
    int n, r;
    cin >> n >> r >> l.b.x >> l.b.y;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].o.x >> c[i].o.y;
        c[i].r = r;
    }
    vector<point> p;
    for (int i = 1; i <= n; ++i) {
        point p1, p2;
        if (line_circle_intersection(c[i], l, p1, p2)) {
            p1.flag = 1;
            p2.flag = -1;
            p.push_back(p1);
            p.push_back(p2);
        }
    }
    sort(p.begin(), p.end(),
         [](const point &a, const point &b) { return a.x < b.x; });
    int ans = 0, cur = 0;
    for (point i : p) {
        cur += i.flag;
        ans = max(ans, abs(cur));
    }
    cout << ans << '\n';

    return 0;
}