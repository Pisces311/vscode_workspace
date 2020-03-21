#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct query {
    int l, r, in;
} q[maxn];

int T, N, M, top, block, cnt;
int a[maxn], num[maxn], aim[maxn];
ll ans, anss[maxn];
map<int, int> ma;

inline void init() {
    ans = 0;
    cnt = 0;
    mem(num, 0);
    ma.clear();
}

bool cmp(const query& a, const query& b) {
    return (a.r / block) == (b.r / block) ? a.l < b.l : a.r < b.r;
}

inline void add(int x) {
    int pos = aim[x];
    ++num[pos];
    if (num[pos] == 1) ans += a[x];
}

inline void del(int x) {
    int pos = aim[x];
    --num[pos];
    if (num[pos] == 0) ans -= a[x];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        block = sqrt(N);
        init();
        up(i, 1, N) {
            scanf("%d", &a[i]);
            if (ma[a[i]] == 0) ma[a[i]] = ++cnt;
            aim[i] = ma[a[i]];
        }
        scanf("%d", &M);
        up(i, 1, M) {
            scanf("%d %d", &q[i].l, &q[i].r);
            q[i].in = i;
        }
        sort(q + 1, q + M + 1, cmp);
        int l = 0, r = 0;
        up(i, 1, M) {
            int ql = q[i].l, qr = q[i].r;
            while (l < ql) del(l++);
            while (l > ql) add(--l);
            while (r < qr) add(++r);
            while (r > qr) del(r--);
            anss[q[i].in] = ans;
        }
        up(i, 1, M) printf("%lld\n", anss[i]);
    }

    return 0;
}