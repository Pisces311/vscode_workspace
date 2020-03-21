#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define mid int m = (l + r) >> 1
const int maxn = 1e5 + 10;

int cnt[maxn << 2];
int len[maxn << 2];
int lp[maxn << 2], rp[maxn << 2];
int num[maxn << 2];
int x[maxn << 2];

struct node {
    int h, l, r;
    int s;
    node() {}
    node(int a, int b, int c, int d) : l(a), r(b), h(c), s(d) {}
    bool operator<(const node &cmp) const {
        if (h == cmp.h) return s > cmp.s;
        return h < cmp.h;
    }
} t[maxn << 2];

void pushup(int l, int r, int rt) {
    if (cnt[rt]) {
        lp[rt] = rp[rt] = 1;
        num[rt] = 2;
        len[rt] = x[r + 1] - x[l];
    } else if (l == r) {
        num[rt] = len[rt] = lp[rt] = rp[rt] = 0;
    } else {
        lp[rt] = lp[rt << 1];
        rp[rt] = rp[rt << 1 | 1];
        len[rt] = len[rt << 1] + len[rt << 1 | 1];
        num[rt] = num[rt << 1] + num[rt << 1 | 1];
        if (lp[rt << 1 | 1] && rp[rt << 1])
            num[rt] -= 2;  // 左右两边两条线重合，变成一条线段
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && R >= r) {
        cnt[rt] += c;
        pushup(l, r, rt);
        return;
    }
    mid;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    pushup(l, r, rt);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        int m = 0;
        while (n--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            x[m] = a;
            t[m++] = node(a, c, b, 1);
            x[m] = c;
            t[m++] = node(a, c, d, -1);
        }
        int k = 1;
        sort(x, x + m);
        sort(t, t + m);
        for (int i = 1; i < m; i++) {
            if (x[i] != x[i - 1]) x[k++] = x[i];
        }
        memset(cnt, 0, sizeof(cnt));
        memset(num, 0, sizeof(num));
        int ret = 0, last = 0;
        for (int i = 0; i < m; i++) {
            int l = lower_bound(x, x + k, t[i].l) - x;
            int r = lower_bound(x, x + k, t[i].r) - x - 1;
            if (l <= r) update(l, r, t[i].s, 0, k - 1, 1);
            ret += num[1] * (t[i + 1].h - t[i].h);
            ret += abs(len[1] - last);
            last = len[1];
        }
        cout << ret << endl;
    }

    return 0;
}