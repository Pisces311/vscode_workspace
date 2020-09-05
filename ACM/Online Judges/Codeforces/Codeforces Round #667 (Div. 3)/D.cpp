#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, s;
ll n;

int get(ll x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
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
        cin >> n >> s;
        ll base = 1, tot = 0;
        while (get(n) > s) {
            while (n % 10 == 0) {
                base *= 10;
                n /= 10;
            }
            int ret = n % 10;
            tot += (10 - ret) * base;
            n += 10 - ret;
        }
        cout << tot << '\n';
    }

    return 0;
}