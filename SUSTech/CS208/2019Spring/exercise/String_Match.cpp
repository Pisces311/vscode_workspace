#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e6 + 10;
const long double PI = acosl(-1.0);

struct cplx {
    long double r, i;
    cplx operator+(const cplx& a) const { return {r + a.r, i + a.i}; }
    cplx operator-(const cplx& a) const { return {r - a.r, i - a.i}; }
    cplx operator*(const cplx& a) const {
        return {r * a.r - i * a.i, r * a.i + i * a.r};
    }
    void divide(int a) {
        r /= a;
        i /= a;
    }
} SA[maxn], SB[maxn], SC[maxn], SD[maxn], SE[maxn], ST[maxn];

int limit, l, n, m, k;
int rev[maxn], ans[maxn];
char s[maxn], t[maxn];

void fft(cplx A[], int type) {
    up(i, 0, limit - 1) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int mid = 1; mid < limit; mid <<= 1) {
        cplx Wn = {cos(PI / mid), type * sin(PI / mid)};
        for (int R = mid << 1, j = 0; j < limit; j += R) {
            cplx w = {1, 0};
            for (int k = 0; k < mid; k++, w = w * Wn) {
                cplx x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
    if (type == -1) up(i, 0, limit - 1) A[i].divide(limit);
}

inline void func(char ch, cplx a[]) {
    mem(ST, 0);
    up(i, 0, m - 1) ST[i] = {(long double)(t[i] == ch ? 1 : 0), 0};
    fft(ST, 1);
    fft(a, 1);
    up(i, 0, limit - 1) a[i] = a[i] * ST[i];
    fft(a, -1);
    up(i, 0, n - m) ans[i] += (int)(a[i + m - 1].r + 0.5);
}

inline void init() {
    mem(SA, 0);
    mem(SB, 0);
    mem(SC, 0);
    mem(SD, 0);
    mem(SE, 0);
    mem(rev, 0);
    mem(ans, 0);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    init();
    scanf("%d %d %d %s %s", &n, &m, &k, s, t);
    up(i, 0, n - 1) {
        up(j, max(0, i - k), min(n, i + k + 1) - 1) {
            if (s[j] == 'A') SA[i] = {1, 0};
            if (s[j] == 'B') SB[i] = {1, 0};
            if (s[j] == 'C') SC[i] = {1, 0};
            if (s[j] == 'D') SD[i] = {1, 0};
            if (s[j] == 'E') SE[i] = {1, 0};
        }
    }
    limit = 1;
    l = 0;
    while (limit <= n + m - 2) limit <<= 1, l++;
    up(i, 0, limit - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    reverse(t, t + m);
    func('A', SA);
    func('B', SB);
    func('C', SC);
    func('D', SD);
    func('E', SE);
    int res = 0;
    up(i, 0, n - m) if (ans[i] == m) res++;
    printf("%d\n", res);

    return 0;
}