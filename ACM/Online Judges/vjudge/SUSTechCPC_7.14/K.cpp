#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll n, k;

ll solve() {
    if (k <= n)
        return k;
    else {
        k -= n;
        ll rem = k % (n - 1);
        if (rem)
            return rem;
        else if (k / (n - 1) % 2 == 0)
            return n;
        else
            return n - 1;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cas = 0;
    while (cin >> n >> k) cout << "Case #" << ++cas << ": " << solve() << '\n';

    return 0;
}