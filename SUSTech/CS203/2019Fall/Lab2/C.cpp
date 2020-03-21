#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, mod;

int cal(int x) {
    int res = 1;
    for (int i = x; i >= 1; --i) res = 1ll * res * i % mod;
    return res;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> mod;
    if (n >= 4)
        cout << 0 << '\n';
    else if (n == 1 || n == 2)
        cout << n % mod << '\n';
    else if (n == 0)
        cout << 1 % mod << '\n';
    else {
        int ans = cal(720);
        cout << ans % mod << '\n';
    }

    return 0;
}