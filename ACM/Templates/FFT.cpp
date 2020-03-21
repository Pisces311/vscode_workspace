#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const double Pi = acos(-1.0);
const double eps = 5e-1;

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