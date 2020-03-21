#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
// G为模意义下的一个原根，Gi为该原根的除法逆元
const int mod = 998244353, G = 3, Gi = 332748118;

// r: 蝴蝶操作相关数组
int n, m, r[maxn];
ll a[maxn], b[maxn], c[maxn];

ll qpow(ll a, ll b) {
    ll ret = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

// len: 大于乘积项数的最小2的整数次幂
inline int init(int len) {
    int ret = 1, L = 0;
    while (ret <= len) ret <<= 1, ++L;
    for (int i = 0; i < ret; ++i)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    return ret;
}

// len: 大于乘积项数的最小2的整数次幂
// on=1: DFT, on=-1: IDFT
void NTT(ll* A, int len, int on) {
    for (int i = 0; i < len; ++i)
        if (i < r[i]) swap(A[i], A[r[i]]);
    for (int mid = 1; mid < len; mid <<= 1) {
        ll Wn = qpow(on == 1 ? G : Gi, (mod - 1) / (mid << 1));
        for (int j = 0; j < len; j += (mid << 1)) {
            ll w = 1;
            for (int k = 0; k < mid; k++, w = (w * Wn) % mod) {
                int x = A[j + k], y = w * A[j + k + mid] % mod;
                A[j + k] = (x + y) % mod, A[j + k + mid] = (x - y + mod) % mod;
            }
        }
    }
    if (on < 0) {
        ll inv = qpow(len, mod - 2);
        for (int i = 0; i < len; ++i) A[i] = (A[i] * inv) % mod;
    }
}