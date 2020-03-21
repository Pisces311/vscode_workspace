#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;

struct query {
    int l, r, in;
} q[maxn];

int N, M, K, block, ans;
int a[maxn], anss[maxn], sum[maxn];

bool cmp(const query& a, const query& b) {
    return (a.r / block) == (b.r / block) ? a.l < b.l : a.r < b.r;
}

inline void add(int x) {
    sum[a[x]]++;
    ans += 2 * sum[a[x]] - 1;
}

inline void del(int x) {
    sum[a[x]]--;
    ans -= 2 * sum[a[x]] + 1;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &N, &M, &K);
    up(i, 1, N) scanf("%d", &a[i]);
    block = sqrt(N);
    up(i, 1, M) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].in = i;
    }
    sort(q + 1, q + M + 1, cmp);
    int l = 1, r = 0;
    up(i, 1, M) {
        int ql = q[i].l, qr = q[i].r;
        while (l < ql) del(l++);
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (r > qr) del(r--);
        anss[q[i].in] = ans;
    }
    up(i, 1, M) printf("%d\n", anss[i]);

    return 0;
}