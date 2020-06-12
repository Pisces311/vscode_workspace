#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e8 + 5;

int n, q;
int prime[maxn], pnum = 0;
bool not_prime[maxn];

void euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) prime[++pnum] = i;
        for (int j = 1; j <= pnum; ++j) {
            if (i * prime[j] > n) break;
            not_prime[i * prime[j]] = true;
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

    cin >> n >> q;
    euler_sieve(n);
    while (q--) {
        int x;
        cin >> x;
        cout << prime[x] << '\n';
    }

    return 0;
}
