#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 99971;

struct SegTreeNode {
    int lazy;
    int sum[50];
} t[maxn << 2];

int T, n, q, tp, l, r;
int a[maxn];

int cal(int x) {
    ll t = 1ll * x * x % mod * x % mod;
    return t;
}

void pushUp(int o, int l, int r) {
    up(i, 0, 47) {
        t[o].sum[i] = t[o << 1].sum[(i + t[o << 1].lazy) % 48] +
                      t[o << 1 | 1].sum[(i + t[o << 1 | 1].lazy) % 48];
        t[o].sum[i] %= mod;
    }
}

void build(int o, int arr[], int l, int r) {
    t[o].lazy = 0;
    if (l == r) {
        t[o].sum[0] = arr[l];
        up(i, 1, 47) t[o].sum[i] = cal(t[o].sum[i - 1]);
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int ql, int qr, int add) {
    if (r < ql || qr < l) return 0;
    add = (add + t[o].lazy) % 48;
    if (ql <= l && r <= qr) return t[o].sum[add];
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr, add) +
            query(o << 1 | 1, mid + 1, r, ql, qr, add)) %
           mod;
}

void update(int o, int l, int r, int ul, int ur) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy = (t[o].lazy + 1) % 48;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur);
    update(o << 1 | 1, mid + 1, r, ul, ur);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        up(i, 1, n) {
            scanf("%d", &a[i]);
            a[i] %= mod;
        }
        build(1, a, 1, n);
        up(i, 1, q) {
            scanf("%d %d %d", &tp, &l, &r);
            if (tp == 1)
                update(1, 1, n, l, r);
            else
                printf("%d\n", query(1, 1, n, l, r, 0));
        }
    }

    return 0;
}