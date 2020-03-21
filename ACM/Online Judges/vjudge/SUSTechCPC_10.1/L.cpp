#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll n, ans;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ans = 0;
    while (n) {
        if (n & 1) ++ans;
        n >>= 1;
    }
    cout << (1ll << ans) << '\n';

    return 0;
}