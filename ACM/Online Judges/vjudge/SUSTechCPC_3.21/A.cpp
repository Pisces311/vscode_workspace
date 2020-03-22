#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 4e5 + 5;
const double Pi = acos(-1.0);
const double eps = 5e-1;

namespace FFT {
struct Complex {
    double r, i;
    void init() { r = i = 0; }
    Complex(double real = 0.0, double image = 0.0) {
        r = real;
        i = image;
    }
    Complex operator+(const Complex o) { return Complex(r + o.r, i + o.i); }
    Complex operator-(const Complex o) { return Complex(r - o.r, i - o.i); }
    Complex operator*(const Complex o) {
        return Complex(r * o.r - i * o.i, r * o.i + i * o.r);
    }
};

void butterfly(Complex *A, int l) {
    for (int i = 1, j = l / 2; i < l - 1; ++i) {
        if (i < j) swap(A[i], A[j]);
        int k = l / 2;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
}

// len: 大于乘积项数的最小2的整数次幂
// on=1: DFT, on=-1: IDFT
void FFT(Complex *A, int len, double on) {
    butterfly(A, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(on * 2 * Pi / h), sin(on * 2 * Pi / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; ++k) {
                Complex u = A[k], t = w * A[k + h / 2];
                A[k] = u + t;
                A[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on < 0)
        for (int i = 0; i < len; i++) A[i].r /= len, A[i].i /= len;
}
}  // namespace FFT

int T, n;
FFT::Complex A[maxn];
int a[maxn / 4];
ll num[maxn], sum[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            num[a[i]]++;
        }
        sort(a, a + n);
        int len = 1;
        while (len <= 2 * a[n - 1]) len <<= 1;
        for (int i = 0; i < len; ++i) A[i].init();
        for (int i = 0; i < len; ++i) A[i].r = num[i];
        FFT::FFT(A, len, 1);
        for (int i = 0; i < len; i++) A[i] = A[i] * A[i];
        FFT::FFT(A, len, -1);
        for (int i = 0; i < len; i++) num[i] = (ll)(A[i].r + eps);
        for (int i = 0; i < n; i++) num[a[i] + a[i]]--;
        for (int i = 0; i < len; i++) num[i] /= 2;
        sum[0] = 0;
        for (int i = 1; i <= len; i++) sum[i] = sum[i - 1] + num[i];
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += sum[len] - sum[a[i]];
            cnt -= 1LL * (i + n - 1) * (n - i) / 2;
        }
        ll tot = 1ll * n * (n - 1) * (n - 2) / 6;
        printf("%.7f\n", 1.0 * cnt / tot);
    }
    return 0;
}
