#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e1 + 5;
const double eps = 1e-8;

// p[1]为最下方的点
struct point {
    double x, y;
} p[maxn], conv[maxn];

struct vct {
    point start, end;
};

int n, m, top;

inline void init() { top = 0; }

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

int T;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        if (cas != 1) cout << '\n';
        init();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i].x >> p[i].y;
            if (p[i].y < p[1].y) swap(p[1], p[i]);
        }
        Graham();
        cout << "Case " << cas << '\n';
        int Min = 1000, id = -1;
        for (int i = 1; i < top; ++i) {
            if (Min > conv[i].x) {
                Min = conv[i].x;
                id = i;
            }
        }
        for (int i = id; i < top; ++i)
            cout << (int)conv[i].x << ' ' << (int)conv[i].y << '\n';
        for (int i = 1; i <= id; ++i)
            cout << (int)conv[i].x << ' ' << (int)conv[i].y << '\n';
        while (m--) {
            point query;
            cin >> query.x >> query.y;
            cout << query.x << ' ' << query.y << " is ";
            if (inside(query))
                cout << "unsafe!\n";
            else
                cout << "safe!\n";
        }
    }

    return 0;
}