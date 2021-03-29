#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll n;

ll cal(ll num) {
    ll ret = 0;
    while (num) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        while (__gcd(n, cal(n)) == 1) ++n;
        cout << n << '\n';
    }

    return 0;
}