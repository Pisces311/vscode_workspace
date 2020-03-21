#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 17;
const double Pi = acos(-1.0);

namespace FFT {
struct Complex {
    double r, i;
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

void brc(Complex *y, int l) {
    for (int i = 1, j = l / 2; i < l - 1; ++i) {
        if (i < j) swap(y[i], y[j]);
        int k = l / 2;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
}

//系数表示法转点值表示法则on为1，做离散傅里叶逆变换则on为-1
void FFT(Complex *y, int len, double on) {
    brc(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(on * 2 * Pi / h), sin(on * 2 * Pi / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; ++k) {
                Complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on < 0)
        for (int i = 0; i < len; i++) y[i].r /= len;
}

}  // namespace FFT

int n;
FFT::Complex a[maxn], b[maxn], c[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        val += 20000;
        ++a[val].r;
        ++b[2 * val].r;
        ++c[3 * val].r;
    }
    FFT::FFT(a, maxn, 1);
    FFT::FFT(b, maxn, 1);
    for (int i = 0; i < maxn; ++i)
        a[i] = a[i] * (a[i] * a[i] - b[i] - b[i] - b[i]);
    FFT::FFT(a, maxn, -1);
    for (int i = 0; i < maxn; ++i) {
        int ret = ((int)(a[i].r + 0.5) + 2 * c[i].r) / 6;
        if (ret) cout << i - 60000 << " : " << ret << '\n';
    }

    return 0;
}