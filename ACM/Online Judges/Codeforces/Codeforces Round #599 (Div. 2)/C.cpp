#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll n;
vector<ll> p;

void get(ll n) {
    p.clear();
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) p.push_back(n);
}

ll solve(ll n) {
    get(n);
    if (p.size() == 1)
        return p[0];
    else
        return 1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cout << solve(n) << '\n';

    return 0;
}