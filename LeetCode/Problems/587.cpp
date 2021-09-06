#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e3 + 5;
constexpr double eps = 1e-8;

// p[1]为最下方的点
struct point {
    double x, y;
    bool operator==(const point& a) const { return x == a.x && y == a.y; }
} p[maxn], conv[maxn];

struct vct {
    point start, end;
};

int n, top;

inline int sign(double a) { return a < -eps ? -1 : a > eps; }
inline double dis(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double cross_product(vct a, vct b) {
    return (a.end.x - a.start.x) * (b.end.y - b.start.y) -
           (b.end.x - b.start.x) * (a.end.y - a.start.y);
}

bool cmp(point p1, point p2) {
    double product = cross_product({p[1], p1}, {p[1], p2});
    return product == 0 ? dis(p[1], p1) < dis(p[1], p2) : product > 0;
}

bool check(point p) {
    for (int i = 1; i <= top; i++)
        if (conv[i] == p) return false;
    return true;
}

void Graham() {
    top = 0;
    for (int i = 1; i <= n; ++i)
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
            swap(p[1], p[i]);
    sort(p + 2, p + n + 1, cmp);
    conv[++top] = p[1];
    for (int i = 2; i <= n; ++i) {
        while (top > 1 && sign(cross_product({conv[top - 1], conv[top]},
                                             {conv[top], p[i]})) < 0)
            --top;
        conv[++top] = p[i];
    }
    if (top >= 2) {
        int ttop = top;
        for (int i = 2; i <= n; i++) {
            if (sign(cross_product({p[i], conv[1]}, {conv[top], p[i]})) == 0) {
                if (check(p[i])) {
                    conv[++ttop] = p[i];
                }
            }
        }
        top = ttop;
    }
}

class Solution {
   public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        n = trees.size();
        for (int i = 0; i < n; i++) {
            p[i + 1] = {(double)trees[i][0], (double)trees[i][1]};
        }
        Graham();
        vector<vector<int>> ret;
        for (int i = 1; i <= top; i++) {
            ret.push_back({(int)conv[i].x, (int)conv[i].y});
        }
        return ret;
    }
};

int main() {
    Solution a;
    vector<vector<int>> v = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    auto ret = a.outerTrees(v);
    for (auto i : ret) {
        cout << i[0] << ' ' << i[1] << endl;
    }
    return 0;
}