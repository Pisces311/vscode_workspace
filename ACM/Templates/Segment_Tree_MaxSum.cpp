#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

//处理区间和并的线段树，区间修改，查询剩余空间的起始位置
//也可多维护一个区间和sum之后用于求带修区间最大子段和

struct SegTreeNode {
    int lmax, rmax, max;
    int lazy;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    int mid = (l + r) >> 1;
    t[o].lmax = t[o << 1].lmax;
    t[o].rmax = t[o << 1 | 1].rmax;
    t[o].max = max(max(t[o << 1].max, t[o << 1 | 1].max),
                   t[o << 1].rmax + t[o << 1 | 1].lmax);
    if (t[o << 1].lmax == mid - l + 1) t[o].lmax += t[o << 1 | 1].lmax;
    if (t[o << 1 | 1].rmax == r - mid) t[o].rmax += t[o << 1].rmax;
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy != -1) {
        int mid = (l + r) >> 1;
        if (t[o].lazy == 0) {
            t[o << 1].lmax = t[o << 1].rmax = t[o << 1].max = 0;
            t[o << 1 | 1].lmax = t[o << 1 | 1].rmax = t[o << 1 | 1].max = 0;
            t[o << 1].lazy = t[o << 1 | 1].lazy = 0;
        } else {
            t[o << 1].lmax = t[o << 1].rmax = t[o << 1].max = mid - l + 1;
            t[o << 1 | 1].lmax = t[o << 1 | 1].rmax = t[o << 1 | 1].max =
                r - mid;
            t[o << 1].lazy = t[o << 1 | 1].lazy = 1;
        }
        t[o].lazy = -1;
    }
}

void build(int o, int l, int r) {
    t[o].lazy = -1;
    if (l == r)
        t[o].lmax = t[o].rmax = t[o].max = 1;
    else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int len) {
    if (l == r) return l;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    if (t[o << 1].max >= len)
        return query(o << 1, l, mid, len);
    else if (t[o << 1].rmax + t[o << 1 | 1].lmax >= len)
        return mid - t[o << 1].rmax + 1;
    else
        return query(o << 1 | 1, mid + 1, r, len);
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        if (val == 1) {
            t[o].lmax = t[o].rmax = t[o].max = r - l + 1;
            t[o].lazy = 1;
        } else {
            t[o].lmax = t[o].rmax = t[o].max = 0;
            t[o].lazy = 0;
        }
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}

int main() { return 0; }