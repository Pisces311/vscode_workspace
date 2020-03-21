#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

struct SegTreeNode {
    int l, r;
    int left, lazy;
} t[maxn << 2];

int T, N, M, K, A, B;

void pushUp(int o) { t[o].left = t[o << 1].left + t[o << 1 | 1].left; }

void pushDown(int o) {
    if (t[o].lazy != -1) {
        t[o << 1].lazy = t[o].lazy;
        t[o << 1 | 1].lazy = t[o].lazy;
        t[o << 1].left = (t[o << 1].r - t[o << 1].l + 1) * t[o].lazy;
        t[o << 1 | 1].left =
            (t[o << 1 | 1].r - t[o << 1 | 1].l + 1) * t[o].lazy;
        t[o].lazy = -1;
    }
}

void build(int o, int l, int r) {
    t[o].l = l;
    t[o].r = r;
    t[o].lazy = -1;
    if (l == r)
        t[o].left = 1;
    else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushUp(o);
    }
}

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].left;
    pushDown(o);
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy = val;
        t[o].left = (r - l + 1) * val;
        return;
    }
    pushDown(o);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        build(1, 0, N - 1);
        up(i, 1, M) {
            scanf("%d %d %d", &K, &A, &B);
            if (K == 1) {
                B = min(B, query(1, 0, N - 1, A, N - 1));
                if (!B) {
                    printf("Can not put any one.\n");
                    continue;
                }
                int mi = A, ma = N - 1, mid;
                int l, r;
                while (mi <= ma) {
                    mid = (mi + ma) >> 1;
                    if (query(1, 0, N - 1, A, mid) > 0) {
                        l = mid;
                        ma = mid - 1;
                    } else
                        mi = mid + 1;
                }
                mi = A, ma = N - 1;
                while (mi <= ma) {
                    mid = (mi + ma) >> 1;
                    if (query(1, 0, N - 1, A, mid) >= B) {
                        r = mid;
                        ma = mid - 1;
                    } else
                        mi = mid + 1;
                }
                update(1, 0, N - 1, l, r, 0);
                printf("%d %d\n", l, r);
            } else {
                printf("%d\n", B - A + 1 - query(1, 0, N - 1, A, B));
                update(1, 0, N - 1, A, B, 1);
            }
        }
        printf("\n");
    }

    return 0;
}