#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll mod = 10007;

int n, m;
ll a[maxn * 10];

struct node {
    int l, r;
    ll val[4], add, mul, cover;
} t[maxn * 4];

ll pow(ll a, int b) {
    ll ans = 1;
    for (int i = 0; i < b; i++) ans = ans * a % mod;
    return ans;
}

void pushUp(int o) {
    if (t[o].l == t[o].r) return;
    up(i, 1, 3) t[o].val[i] = (t[o << 1].val[i] + t[o << 1 | 1].val[i]) % mod;
}

void pushDown(int o) {
    if (t[o].l == t[o].r) return;
    if (t[o].cover != -1) {
        int l = t[o << 1].l, r = t[o << 1].r;
        t[o << 1].add = 0;
        t[o << 1].mul = 1;
        t[o << 1].cover = t[o].cover;
        up(i, 1, 3) t[o << 1].val[i] =
            (ll)(r - l + 1) * (ll)pow(t[o].cover, i) % mod;
        l = t[o << 1 | 1].l, r = t[o << 1 | 1].r;
        t[o << 1 | 1].add = 0;
        t[o << 1 | 1].mul = 1;
        t[o << 1 | 1].cover = t[o].cover;
        up(i, 1, 3) t[o << 1 | 1].val[i] =
            (ll)(r - l + 1) * (ll)pow(t[o].cover, i) % mod;
        t[o].cover = -1;
    }
    if (t[o].mul != 1) {
        t[o << 1].mul = (t[o << 1].mul * t[o].mul) % mod;
        t[o << 1].add = (t[o << 1].add * t[o].mul) % mod;
        up(i, 1, 3) t[o << 1].val[i] =
            (t[o << 1].val[i] * (ll)pow(t[o].mul, i)) % mod;
        t[o << 1 | 1].mul = (t[o << 1 | 1].mul * t[o].mul) % mod;
        t[o << 1 | 1].add = (t[o << 1 | 1].add * t[o].mul) % mod;
        up(i, 1, 3) t[o << 1 | 1].val[i] =
            (t[o << 1 | 1].val[i] * (ll)pow(t[o].mul, i)) % mod;
        t[o].mul = 1;
    }
    if (t[o].add) {
        int l = t[o << 1].l, r = t[o << 1].r;
        ll add = t[o].add;
        t[o << 1].add = (t[o << 1].add + t[o].add) % mod;
        t[o << 1].val[3] =
            (t[o << 1].val[3] + 3 * t[o << 1].val[1] * add * add +
             3 * t[o << 1].val[2] * add + (ll)(r - l + 1) * add * add * add) %
            mod;
        t[o << 1].val[2] = (t[o << 1].val[2] + 2 * t[o << 1].val[1] * add +
                            (ll)(r - l + 1) * add * add) %
                           mod;
        t[o << 1].val[1] = (t[o << 1].val[1] + (ll)(r - l + 1) * add) % mod;

        l = t[o << 1 | 1].l, r = t[o << 1 | 1].r;
        t[o << 1 | 1].add = (t[o << 1 | 1].add + t[o].add) % mod;
        t[o << 1 | 1].val[3] =
            (t[o << 1 | 1].val[3] + 3 * t[o << 1 | 1].val[1] * add * add +
             3 * t[o << 1 | 1].val[2] * add +
             (ll)(r - l + 1) * add * add * add) %
            mod;
        t[o << 1 | 1].val[2] =
            (t[o << 1 | 1].val[2] + 2 * t[o << 1 | 1].val[1] * add +
             (ll)(r - l + 1) * add * add) %
            mod;
        t[o << 1 | 1].val[1] =
            (t[o << 1 | 1].val[1] + (ll)(r - l + 1) * add) % mod;
        t[o].add = 0;
    }
}

void build(int l, int r, int o) {
    t[o].l = l;
    t[o].r = r;
    up(i, 1, 3) t[o].val[i] = 0;
    t[o].add = 0;
    t[o].mul = 1;
    t[o].cover = -1;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, o << 1);
    build(mid + 1, r, o << 1 | 1);
}

void update(int l, int r, int o, ll add, int type) {
    add %= mod;
    if (type == 1) {
        if (t[o].l == l && t[o].r == r) {
            t[o].val[3] =
                (t[o].val[3] + 3 * t[o].val[1] * add * add +
                 3 * t[o].val[2] * add + (ll)(r - l + 1) * add * add * add) %
                mod;
            t[o].val[2] = (t[o].val[2] + 2 * t[o].val[1] * add +
                           (ll)(r - l + 1) * add * add) %
                          mod;
            t[o].val[1] = (t[o].val[1] + (ll)(r - l + 1) * add) % mod;
            t[o].add = (t[o].add + add) % mod;
            return;
        }
    } else if (type == 2) {
        if (t[o].l == l && t[o].r == r) {
            up(i, 1, 3) t[o].val[i] = (t[o].val[i] * (ll)pow(add, i)) % mod;
            t[o].mul = t[o].mul * add % mod;
            t[o].add = t[o].add * add % mod;
            return;
        }
    } else {
        if (t[o].l == l && t[o].r == r) {
            up(i, 1, 3) t[o].val[i] = (ll)(r - l + 1) * (ll)pow(add, i) % mod;
            t[o].add = 0;
            t[o].mul = 1;
            t[o].cover = add;
            return;
        }
    }
    pushDown(o);
    int mid = (t[o].l + t[o].r) >> 1;
    if (r <= mid)
        update(l, r, o << 1, add, type);
    else if (l > mid)
        update(l, r, o << 1 | 1, add, type);
    else if (l <= mid && r > mid) {
        update(l, mid, o << 1, add, type);
        update(mid + 1, r, o << 1 | 1, add, type);
    }
    pushUp(o);
}

int query(int o, int l, int r, int type) {
    if (t[o].l == l && t[o].r == r) return t[o].val[type];
    pushDown(o);
    int mid = (t[o].l + t[o].r) >> 1;
    if (r <= mid)
        return query(o << 1, l, r, type);
    else if (l > mid)
        return query(o << 1 | 1, l, r, type);
    else
        return (query(o << 1, l, mid, type) +
                query(o << 1 | 1, mid + 1, r, type)) %
               mod;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (true) {
        scanf("%d %d", &n, &m);
        if (n + m == 0) break;
        build(1, n, 1);
        while (m--) {
            int k, x, y, c;
            scanf("%d %d %d %d", &k, &x, &y, &c);
            if (k == 4)
                printf("%d\n", query(1, x, y, c));
            else
                update(x, y, 1, (ll)c, k);
        }
    }

    return 0;
}