#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int lmax, rmax, max;
    int lazy;
} NS[maxn << 2], DS[maxn << 2];

int CASE, T, N, QT, L, R, ans;
char op[10];

void pushUp(int o, int l, int r, SegTreeNode t[]) {
    int mid = (l + r) >> 1;
    t[o].lmax = t[o << 1].lmax;
    t[o].rmax = t[o << 1 | 1].rmax;
    t[o].max = max(max(t[o << 1].max, t[o << 1 | 1].max),
                   t[o << 1].rmax + t[o << 1 | 1].lmax);
    if (t[o << 1].lmax == mid - l + 1) t[o].lmax += t[o << 1 | 1].lmax;
    if (t[o << 1 | 1].rmax == r - mid) t[o].rmax += t[o << 1].rmax;
}

void pushDown(int o, int l, int r, SegTreeNode t[]) {
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

void build(int o, int l, int r, SegTreeNode t[]) {
    t[o].lazy = -1;
    if (l == r)
        t[o].lmax = t[o].rmax = t[o].max = 1;
    else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid, t);
        build(o << 1 | 1, mid + 1, r, t);
        pushUp(o, l, r, t);
    }
}

int query(int o, int l, int r, int len, SegTreeNode t[]) {
    if (l == r) return l;
    pushDown(o, l, r, t);
    int mid = (l + r) >> 1;
    if (t[o << 1].max >= len)
        return query(o << 1, l, mid, len, t);
    else if (t[o << 1].rmax + t[o << 1 | 1].lmax >= len)
        return mid - t[o << 1].rmax + 1;
    else
        return query(o << 1 | 1, mid + 1, r, len, t);
}

void update(int o, int l, int r, int ul, int ur, int val, SegTreeNode t[]) {
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
    pushDown(o, l, r, t);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val, t);
    update(o << 1 | 1, mid + 1, r, ul, ur, val, t);
    pushUp(o, l, r, t);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &CASE);
    up(case_num, 1, CASE) {
        printf("Case %d:\n", case_num);
        scanf("%d %d", &T, &N);
        build(1, 1, T, NS);
        build(1, 1, T, DS);
        up(i, 1, N) {
            scanf("%s", op);
            if (op[0] == 'N') {
                scanf("%d", &QT);
                if (DS[1].max >= QT) {
                    ans = query(1, 1, T, QT, DS);
                    printf("%d,don't put my gezi\n", ans);
                    update(1, 1, T, ans, ans + QT - 1, 0, DS);
                    update(1, 1, T, ans, ans + QT - 1, 0, NS);
                } else if (NS[1].max >= QT) {
                    ans = query(1, 1, T, QT, NS);
                    printf("%d,don't put my gezi\n", ans);
                    update(1, 1, T, ans, ans + QT - 1, 0, DS);
                    update(1, 1, T, ans, ans + QT - 1, 0, NS);
                } else
                    printf("wait for me\n");
            } else if (op[0] == 'D') {
                scanf("%d", &QT);
                if (DS[1].max >= QT) {
                    ans = query(1, 1, T, QT, DS);
                    printf("%d,let's fly\n", ans);
                    update(1, 1, T, ans, ans + QT - 1, 0, DS);
                } else
                    printf("fly with yourself\n");
            } else {
                scanf("%d %d", &L, &R);
                update(1, 1, T, L, R, 1, DS);
                update(1, 1, T, L, R, 1, NS);
                printf("I am the hope of chinese chengxuyuan!!\n");
            }
        }
    }

    return 0;
}