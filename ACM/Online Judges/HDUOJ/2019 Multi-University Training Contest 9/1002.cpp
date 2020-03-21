#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int x, y;
    bool operator<(const node& a) const { return y < a.y; }
};

int T, n, m, K;
node L[maxn], R[maxn], U[maxn], D[maxn];
int dcx[maxn], dcy[maxn], topx, topy, topl, topr, topu, topd;
int num[maxn << 2];

inline void init() {
    topx = topy = 0;
    topl = topr = topu = topd = 0;
}

void pushUp(int o, int l, int r) { num[o] = num[o << 1] + num[o << 1 | 1]; }

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return num[o];
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (l == r) {
        num[o] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d %d", &n, &m, &K);
        for (int i = 1; i <= K; ++i) {
            int x, y;
            char dir;
            scanf("%d %d %c", &x, &y, &dir);
            if (dir == 'L') L[++topl] = {x, y};
            if (dir == 'R') R[++topr] = {x, y};
            if (dir == 'U') U[++topu] = {x, y};
            if (dir == 'D') D[++topd] = {x, y};
            dcx[++topx] = x;
            dcy[++topy] = y;
        }
        sort(dcx + 1, dcx + topx + 1);
        sort(dcy + 1, dcy + topy + 1);
        sort(L + 1, L + topl + 1);
        sort(R + 1, R + topr + 1);
        sort(U + 1, U + topu + 1);
        sort(D + 1, D + topd + 1);
        ll ans = 1;
        memset(num, 0, sizeof(num));
        for (int i = 1, j = 1; i <= topd; ++i) {
            int tar = lower_bound(dcx + 1, dcx + topx + 1, D[i].x) - dcx;
            while (j <= topl && L[j].y <= D[i].y) {
                int pos = lower_bound(dcx + 1, dcx + topx + 1, L[j].x) - dcx;
                update(1, 1, topx, pos, 1);
                ++j;
            }
            ans += query(1, 1, topx, tar, topx);
        }
        memset(num, 0, sizeof(num));
        for (int i = 1, j = 1; i <= topd; ++i) {
            int tar = lower_bound(dcx + 1, dcx + topx + 1, D[i].x) - dcx;
            while (j <= topr && R[j].y <= D[i].y) {
                int pos = lower_bound(dcx + 1, dcx + topx + 1, R[j].x) - dcx;
                update(1, 1, topx, pos, 1);
                ++j;
            }
            ans += query(1, 1, topx, 1, tar);
        }
        memset(num, 0, sizeof(num));
        for (int i = topu, j = topl; i >= 1; --i) {
            int tar = lower_bound(dcx + 1, dcx + topx + 1, U[i].x) - dcx;
            while (j >= 1 && L[j].y >= U[i].y) {
                int pos = lower_bound(dcx + 1, dcx + topx + 1, L[j].x) - dcx;
                update(1, 1, topx, pos, 1);
                --j;
            }
            ans += query(1, 1, topx, tar, topx);
        }
        memset(num, 0, sizeof(num));
        for (int i = topu, j = topr; i >= 1; --i) {
            int tar = lower_bound(dcx + 1, dcx + topx + 1, U[i].x) - dcx;
            while (j >= 1 && R[j].y >= U[i].y) {
                int pos = lower_bound(dcx + 1, dcx + topx + 1, R[j].x) - dcx;
                update(1, 1, topx, pos, 1);
                --j;
            }
            ans += query(1, 1, topx, 1, tar);
        }
        printf("%lld\n", ans);
    }

    return 0;
}