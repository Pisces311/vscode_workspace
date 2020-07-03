#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T;
ll n;
int prime[maxn], pnum = 0;  // 质数与质数个数
bool not_prime[maxn];

// 对1~n使用欧拉筛
void euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            prime[++pnum] = i;
        }
        for (int j = 1; j <= pnum; ++j) {
            if (i * prime[j] > n) break;
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int deal(ll &x) {
    int ret = INT_MAX;
    for (int i = 1; i <= pnum; ++i) {
        if (x % prime[i] == 0) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                x /= prime[i];
                ++cnt;
            }
            ret = min(ret, cnt);
        }
    }
    return ret;
}

bool solve2(ll x) {
    ll r = sqrt(x) + 0.5;
    if (r * r == x)
        return true;
    else
        return false;
}

bool solve3(ll x) {
    ll r = pow(x, 1.0 / 3) + 0.5;
    if (r * r * r == x)
        return true;
    else
        return false;
}

bool solve4(ll x) {
    ll r = pow(x, 1.0 / 4) + 0.5;
    if (r * r * r * r == x)
        return true;
    else
        return false;
}

int solve() {
    int ans = deal(n);
    if (n == 1)
        return ans;
    else if (solve4(n))
        return min(ans, 4);
    else if (solve3(n))
        return min(ans, 3);
    else if (solve2(n))
        return min(ans, 2);
    else
        return 1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    euler_sieve(1e4);
    cin >> T;
    while (T--) {
        cin >> n;
        cout << solve() << '\n';
    }

    return 0;
}