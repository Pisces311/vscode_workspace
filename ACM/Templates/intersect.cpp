#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 3e1 + 5;

struct point {
    double x, y;
};

double Dir(point p1, point p2, point p0) {  //判断线段p0p2相对于线段p0p1的位置
    //向量p0p1叉乘向量p0p2，转化为行列式进行计算
    //结果若大于0，则p0p2沿顺时钟方向旋转可得到与p0p1同方向的向量
    //结果若小于0，则p0p2沿逆时钟方向旋转可得到与p0p1同方向的向量
    //结果若等于0，则p0p2与p0p1共线
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int on_seg(point p1, point p2, point p0) {
    double minx, maxx, miny, maxy;
    minx = min(p1.x, p2.x);
    maxx = max(p1.x, p2.x);
    miny = min(p1.y, p2.y);
    maxy = max(p1.y, p2.y);
    return minx <= p0.x && p0.x <= maxx && miny <= p0.y && p0.y <= maxy;
}

// 规范相交
bool intersect(point p1, point p2, point p3, point p4) {  //两线段相交有两种情况
    double d1 = Dir(p4, p1, p3);
    double d2 = Dir(p4, p2, p3);
    double d3 = Dir(p2, p3, p1);
    double d4 = Dir(p2, p4, p1);
    if (d1 * d2 < 0 && d3 * d4 < 0)  // cross
        return true;
    // on
    if (d1 == 0 && on_seg(p3, p4, p1)) return true;
    if (d2 == 0 && on_seg(p3, p4, p2)) return true;
    if (d3 == 0 && on_seg(p1, p2, p3)) return true;
    if (d4 == 0 && on_seg(p1, p2, p4)) return true;
    return false;
}