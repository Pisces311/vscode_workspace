#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

// p[1]为最下方的点
struct Point {
    double x, y;
    bool operator<(const Point& rhs) const {
        return y == rhs.y ? x < rhs.x : y < rhs.y;
    }
    double dis(const Point& rhs) { return hypot(x - rhs.x, y - rhs.y); }
};

struct Vector {
    Point start, end;
    // 叉积的右手定则
    double cross_prod(const Vector& rhs) {
        return (end.x - start.x) * (rhs.end.y - rhs.start.y) -
               (rhs.end.x - rhs.start.x) * (end.y - start.y);
    }
};

inline int sign(double a) { return a < -eps ? -1 : a > eps; }

vector<Point> Graham(vector<Point>& p) {
    int n = p.size();
    for (int i = 0; i < n; i++)
        if (p[i] < p[0]) swap(p[i], p[0]);
    sort(p.begin() + 1, p.end(), [&](Point a, Point b) {
        double prod = (Vector){p[0], a}.cross_prod({p[0], b});
        return prod == 0 ? p[0].dis(a) < p[0].dis(b) : prod > 0;
    });
    vector<Point> conv;
    conv.push_back(p[0]);
    for (int i = 1; i < n; i++) {
        while (conv.size() > 1 &&
               sign((Vector){*(conv.rbegin() + 1), *conv.rbegin()}.cross_prod(
                   {*conv.rbegin(), p[i]})) <= 0)
            conv.pop_back();
        conv.push_back(p[i]);
    }
    conv.push_back(p[0]);
    return conv;
}

double polygon_area(vector<Point> polygon) {
    int n = polygon.size();
    if (n < 4) return 0;
    double area = 0;
    Point origin = {0, 0};
    for (int i = 0; i < n - 1; i++)
        area +=
            (Vector){origin, polygon[i]}.cross_prod({origin, polygon[i + 1]});
    area = fabs(area / 2.0);
    return area;
}

double polygon_perimeter(vector<Point> polygon) {
    double perimeter = 0;
    for (int i = 0; i < polygon.size() - 1; i++)
        perimeter += polygon[i].dis(polygon[i + 1]);
    return perimeter;
}

bool inside(vector<Point> polygon, Point x) {
    for (int i = 0; i < polygon.size() - 1; i++)
        if ((Vector){x, polygon[i]}.cross_prod({x, polygon[i + 1]}) <= eps)
            return false;
    return true;
}