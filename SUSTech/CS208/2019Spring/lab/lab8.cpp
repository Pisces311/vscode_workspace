#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int MAXN = 4e5 + 10;
const double PI = acos(-1.0);

struct cplx {
    double x, y;
    cplx operator+(const cplx& a) const { return {x + a.x, y + a.y}; }
    cplx operator-(const cplx& a) const { return {x - a.x, y - a.y}; }
    cplx operator*(const cplx& a) const {
        return {x * a.x - y * a.y, x * a.y + y * a.x};
    }
} va[MAXN * 2 + MAXN / 2], vb[MAXN * 2 + MAXN / 2];

bool ispri[maxn];
int len = 1, N, M;
int pri[maxn], zyz[maxn];
int f[MAXN], g[MAXN], id[MAXN], cnt[MAXN], rnk[MAXN], rev[MAXN * 2 + MAXN / 2];
ll vz[MAXN], ans[MAXN];
vector<ll> conv, multi;

void find_pri(int N) {
    mem(ispri, true);
    ispri[1] = false;
    up(i, 2, N - 1) {
        if (ispri[i]) pri[++pri[0]] = i;
        for (int j = 1; j <= pri[0] && (ll)i * (ll)pri[j] < N; ++j) {
            ispri[i * pri[j]] = false;
            if (i % pri[j] == 0) break;
        }
    }
}

ll power(ll x, ll p, ll mod) {
    if (!p) return 1ll;
    ll ret = power(x, p >> 1, mod);
    ret = ret * ret % mod;
    if ((p & 1ll) == 1ll) ret = (x % mod * ret) % mod;
    return ret;
}

inline bool check(int g, int x) {
    up(i, 1, zyz[0]) {
        if (power((ll)g, (ll)((x - 1) / zyz[i]), (ll)x) == 1) return false;
    }
    return true;
}

int find_root(int x) {
    int tmp = x - 1;
    for (int i = 1; tmp && i <= pri[0]; ++i) {
        if (tmp % pri[i] == 0) {
            zyz[++zyz[0]] = pri[i];
            while (tmp % pri[i] == 0) tmp /= pri[i];
        }
    }
    up(g, 2, x - 1) if (check(g, x)) return g;
    return 0;
}

void init() {
    int tim = 0;
    len = 1;
    conv.clear();
    multi.clear();
    mem(va, 0);
    mem(vb, 0);
    while (len <= N + M - 2) len <<= 1, tim++;
    up(i, 0, len - 1) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (tim - 1));
}

void FFT(cplx A[], const int fla) {
    up(i, 0, len - 1) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int i = 1; i < len; i <<= 1) {
        const cplx w = {cos(PI / i), fla * sin(PI / i)};
        for (int j = 0; j < len; j += (i << 1)) {
            cplx K = {1, 0};
            for (int k = 0; k < i; k++, K = K * w) {
                const cplx x = A[j + k], y = K * A[j + k + i];
                A[j + k] = x + y;
                A[j + k + i] = x - y;
            }
        }
    }
}

void getConv() {
    init();
    up(i, 0, N - 1) va[i].x = f[i];
    up(i, 0, M - 1) vb[i].x = g[i];
    FFT(va, 1);
    FFT(vb, 1);
    up(i, 0, len - 1) va[i] = va[i] * vb[i];
    FFT(va, -1);
    up(i, 0, N + M - 2) conv.push_back((ll)(va[i].x / len + 0.5));
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    find_pri(maxn - 1);
    int n, P;
    scanf("%d %d", &n, &P);
    int rt = find_root(P);
    ll idx = 1;
    up(i, 0, P - 2) {
        id[idx] = i;
        rnk[i] = idx;
        idx = idx * rt % P;
    }
    up(i, 1, n) {
        ll tmp;
        scanf("%lld", &tmp);
        vz[i] = tmp;
        tmp %= P;
        if (tmp == 0) continue;
        cnt[id[tmp]]++;
    }
    N = M = P;
    up(i, 0, P - 2) f[i] = g[i] = cnt[i];
    getConv();
    up(i, 0, (int)conv.size() - 1) {
        ll tmp = conv[i];
        ans[rnk[i % (P - 1)]] += tmp;
    }
    ll tot = (ll)n * n;
    up(i, 1, P - 1) tot -= ans[i];
    ans[0] = tot;
    up(i, 0, P - 1) printf("%lld\n", ans[i]);

    return 0;
}