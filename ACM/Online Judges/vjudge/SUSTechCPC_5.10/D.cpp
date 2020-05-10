#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 3e1 + 5;

/*
部分重合，端点重合，点边重合都会返回true
*/
struct point {
    double x, y;
};

struct segment {
    point start, end;
} seg[maxn];

int n;

double Dir(point p1, point p2, point p0) {  //判断线段p0p2相对于线段p0p1的位置
    //向量p0p1叉乘向量p0p2，转化为行列式进行计算
    //结果若大于0，则p0p2沿顺时钟方向旋转可得到与p0p1同方向的向量
    //结果若小于0，则p0p2沿逆时钟方向旋转可得到与p0p1同方向的向量
    //结果若等于0，则p0p2与p0p1共线
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int OnSgm(point p1, point p2, point p0) {
    double minx, maxx, miny, maxy;
    minx = min(p1.x, p2.x);
    maxx = max(p1.x, p2.x);
    miny = min(p1.y, p2.y);
    maxy = max(p1.y, p2.y);
    return minx <= p0.x && p0.x <= maxx && miny <= p0.y && p0.y <= maxy;
}

bool Intersect(point p1, point p2, point p3, point p4) {  //两线段相交有两种情况
    double d1, d2, d3, d4;
    d1 = Dir(p4, p1, p3);
    d2 = Dir(p4, p2, p3);
    d3 = Dir(p2, p3, p1);
    d4 = Dir(p2, p4, p1);
    if (d1 * d2 < 0 && d3 * d4 < 0)  //两线段互相跨过
        return 1;
    //一条直线有一个端点在另外一条直线上
    if (d1 == 0 && OnSgm(p3, p4, p1)) return 1;
    if (d2 == 0 && OnSgm(p3, p4, p2)) return 1;
    if (d3 == 0 && OnSgm(p1, p2, p3)) return 1;
    if (d4 == 0 && OnSgm(p1, p2, p4)) return 1;
    return 0;  //两线段不相交返回false
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> seg[i].start.x >> seg[i].start.y >> seg[i].end.x >> seg[i].end.y;
    point target;
    cin >> target.x >> target.y;
    int ans = n;
    for (double x = 0, y = 0; x <= 100; x += 0.5) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (Intersect({x, y}, target, seg[i].start, seg[i].end)) ++cnt;
        ans = min(ans, cnt);
    }
    for (double x = 100, y = 0; y <= 100; y += 0.5) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (Intersect({x, y}, target, seg[i].start, seg[i].end)) ++cnt;
        ans = min(ans, cnt);
    }
    for (double x = 100, y = 100; x >= 0; x -= 0.5) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (Intersect({x, y}, target, seg[i].start, seg[i].end)) ++cnt;
        ans = min(ans, cnt);
    }
    for (double x = 0, y = 100; y >= 0; y -= 0.5) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (Intersect({x, y}, target, seg[i].start, seg[i].end)) ++cnt;
        ans = min(ans, cnt);
    }
    cout << "Number of doors = " << ans + 1 << '\n';

    return 0;
}