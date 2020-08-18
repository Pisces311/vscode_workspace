#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e8 + 5;

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