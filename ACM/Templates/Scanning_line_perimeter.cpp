#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;
const int maxx = 2e4 + 5;
const int inf = 0x3f3f3f3f;

//横边
//[l, r]线段的左端点和右端点（记得实际使用时右端点要减一）
// h: 高度
// f: 为1则为下边，为0则为上边
struct Edge {
    int l, r, h, f;
    bool operator<(const Edge& a) const { return h < a.h; }
} edge[maxn << 1];

// len: 长度
// cnt: 被覆盖的次数
// num: 被几条不相邻的线段覆盖
// lc, rc: 左端点和右端点是否被覆盖
struct SegTreeNode {
    int len, cnt, num;
    bool lc, rc;
} t[maxx << 2];

void pushUp(int o, int l, int r) {
    if (t[o].cnt) {
        t[o].len = r - l + 1;
        t[o].lc = t[o].rc = true;
        t[o].num = 1;
    } else if (l == r) {
        t[o].len = 0;
        t[o].lc = t[o].rc = false;
        t[o].num = 0;
    } else {
        t[o].len = t[o << 1].len + t[o << 1 | 1].len;
        t[o].lc = t[o << 1].lc;
        t[o].rc = t[o << 1 | 1].rc;
        t[o].num = t[o << 1].num + t[o << 1 | 1].num -
                   (t[o << 1].rc & t[o << 1 | 1].lc);
    }
}

void build(int o, int l, int r) {
    t[o].cnt = 0;
    t[o].len = 0;
    t[o].lc = t[o].rc = false;
    t[o].num = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].cnt += val;
        pushUp(o, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

int main() { return 0; }