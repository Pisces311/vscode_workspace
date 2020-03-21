#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int m, p, e, k, n;
int num[maxn << 2];

void pushUp(int o, int l, int r) { num[o] = num[o << 1] + num[o << 1 | 1]; }

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return num[o];
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

int query(int o, int l, int r, int k) {
    if (num[o] < k) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (k <= num[o << 1])
        return query(o << 1, l, mid, k);
    else
        return query(o << 1 | 1, mid + 1, r, k - num[o << 1]);
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (l == r) {
        if (num[o] + val < 0) {
            printf("No Elment!\n");
            return;
        }
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

    while (~scanf("%d", &m)) {
        mem(num, 0);
        while (m--) {
            scanf("%d %d", &p, &e);
            if (!p)
                update(1, 1, 1e5, e, 1);
            else if (p == 1)
                update(1, 1, 1e5, e, -1);
            else {
                scanf("%d", &k);
                n = query(1, 1, 1e5, 1, e);
                k += n;
                n = query(1, 1, 1e5, k);
                if (n == -1)
                    printf("Not Find!\n");
                else
                    printf("%d\n", n);
            }
        }
    }

    return 0;
}