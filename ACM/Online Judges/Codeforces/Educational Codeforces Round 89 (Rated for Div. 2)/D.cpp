#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e7 + 5;

int n;
ll a[maxn];
vector<ll> l, r;
int prime[maxn], pnum = 0;
int pf[maxn];
bool not_prime[maxn];

void euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            prime[++pnum] = i;
            pf[i] = i;
        }
        for (int j = 1; j <= pnum; ++j) {
            if (i * prime[j] > n) break;
            not_prime[i * prime[j]] = true;
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

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    euler_sieve(1e7);
    for (int i = 1; i <= n; ++i) {
        int lans = 1;
        int pfac = pf[a[i]];
        while (a[i] % pfac == 0) {
            a[i] /= pfac;
            lans *= pfac;
        }
        if (a[i] != 1) {
            l.push_back(lans);
            r.push_back(a[i]);
        } else {
            l.push_back(-1);
            r.push_back(-1);
        }
    }
    for (int i : l) cout << i << ' ';
    cout << '\n';
    for (int i : r) cout << i << ' ';
    cout << '\n';

    return 0;
}