#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
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
struct SegTreeNode {
    int len, cnt;
} t[maxn << 3];

void pushUp(int o, int l, int r) {
    if (t[o].cnt)
        t[o].len = r - l + 1;
    else if (l == r)
        t[o].len = 0;
    else
        t[o].len = t[o << 1].len + t[o << 1 | 1].len;
}

void build(int o, int l, int r) {
    t[o].len = 0;
    t[o].cnt = 0;
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