#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int d;

int prime[maxn], pnum = 0;  // 质数与质数个数
int pf[maxn];               // 最小质因子
bool nprime[maxn];

// 对1~n使用欧拉筛
void euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!nprime[i]) {
            prime[++pnum] = i;
            pf[i] = i;
        }
        for (int j = 1; j <= pnum; ++j) {
            if (i * prime[j] > n) break;
            nprime[i * prime[j]] = true;
            pf[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    euler_sieve(1e6);
    int t;
    cin >> t;
    while (t--) {
        cin >> d;
        int fac1;
        for (fac1 = 1 + d; nprime[fac1]; ++fac1)
            ;
        int fac2;
        for (fac2 = fac1 + d; nprime[fac2]; ++fac2)
            ;
        cout << fac1 * fac2 << '\n';
    }

    return 0;
}