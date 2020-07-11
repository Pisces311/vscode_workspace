#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 1e9 + 7;

int T;
ll n;

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

namespace linear_seq {
constexpr int maxn = 1e5 + 5;
ll res[maxn], base[maxn], _c[maxn], _md[maxn];

vector<int> Md;

void mul(ll *a, ll *b, int k) {
    for (int i = 0; i < 2 * k; ++i) _c[i] = 0;
    for (int i = 0; i < k; ++i)
        if (a[i]) {
            for (int j = 0; j < k; ++j)
                _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
        }
    for (int i = k + k - 1; i >= k; --i)
        if (_c[i]) {
            for (int j : Md)
                _c[i - k + j] = (_c[i - k + j] - _c[i] * _md[j]) % mod;
        }
    for (int i = 0; i < k; ++i) a[i] = _c[i];
}

int solve(ll n, vector<int> a,
          vector<int> b) {  // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
    ll ans = 0, pnt = 0;
    int k = a.size();
    assert(a.size() == b.size());
    for (int i = 0; i < k; ++i) _md[k - 1 - i] = -a[i];
    _md[k] = 1;
    Md.clear();
    for (int i = 0; i < k; ++i)
        if (_md[i]) Md.push_back(i);
    for (int i = 0; i < k; ++i) res[i] = base[i] = 0;
    res[0] = 1;
    while ((1ll << pnt) <= n) ++pnt;
    for (int p = pnt; p >= 0; p--) {
        mul(res, res, k);
        if ((n >> p) & 1) {
            for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
            res[0] = 0;
            for (int j : Md) res[j] = (res[j] - res[k] * _md[j]) % mod;
        }
    }
    for (int i = 0; i < k; ++i) ans = (ans + res[i] * b[i]) % mod;
    if (ans < 0) ans += mod;
    return ans;
}

vector<int> BM(vector<int> s) {
    vector<int> C(1, 1), B(1, 1);
    int L = 0, m = 1, b = 1;
    for (int n = 0; n < s.size(); ++n) {
        ll d = 0;
        for (int i = 0; i <= L; ++i) d = (d + (ll)C[i] * s[n - i]) % mod;
        if (d == 0)
            ++m;
        else if (2 * L <= n) {
            vector<int> T = C;
            ll c = mod - d * qpow(b, mod - 2) % mod;
            while (C.size() < B.size() + m) C.push_back(0);
            for (int i = 0; i < B.size(); ++i)
                C[i + m] = (C[i + m] + c * B[i]) % mod;
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            ll c = mod - d * qpow(b, mod - 2) % mod;
            while (C.size() < B.size() + m) C.push_back(0);
            for (int i = 0; i < B.size(); ++i)
                C[i + m] = (C[i + m] + c * B[i]) % mod;
            ++m;
        }
    }
    return C;
}

int gao(vector<int> a, ll n) {
    vector<int> c = BM(a);
    c.erase(c.begin());
    for (int i = 0; i < c.size(); ++i) c[i] = (mod - c[i]) % mod;
    return solve(n, c, vector<int>(a.begin(), a.begin() + c.size()));
}
};  // namespace linear_seq

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 打表前8~10项左右，最后调用gao()得第n项
    vector<int> v({3, 9, 20, 46, 106, 244, 560, 1286, 2956, 6794});
    cin >> T;
    while (T--) {
        cin >> n;
        cout << linear_seq::gao(v, n - 1) << '\n';
    }

    return 0;
}