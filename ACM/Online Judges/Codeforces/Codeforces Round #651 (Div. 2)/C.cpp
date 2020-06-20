#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
vector<ll> fac;

void get(ll n) {
    fac.clear();
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            if (i & 1) fac.push_back(i);
        }
    }
    if (n > 1 && n & 1) fac.push_back(n);
}

bool check() {
    if (n == 1)
        return false;
    else if (n == 2 || n & 1)
        return true;
    else {
        get(n);
        if (!fac.size())
            return false;
        else if (fac.size() == 1) {
            n /= fac[0];
            if (n == 2)
                return false;
            else
                return true;
        } else
            return true;
    }
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
        if (check()) {
            cout << "Ashishgup\n";
        } else {
            cout << "FastestFinger\n";
        }
    }

    return 0;
}