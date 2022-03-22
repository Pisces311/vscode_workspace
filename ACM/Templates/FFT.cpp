#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void FFT(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd& x : a) x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b, bool normal) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    FFT(fa, true);

    vector<int> c(a.size() + b.size() - 1);
    for (int i = 0; i < c.size(); i++) c[i] = round(fa[i].real());

    if (normal) {
        int carry = 0;
        for (int i = 0; i < c.size(); i++) {
            c[i] += carry;
            carry = c[i] / 10;
            c[i] %= 10;
        }
        while (carry) {
            c.push_back(carry % 10);
            carry /= 10;
        }
    }

    return c;
}