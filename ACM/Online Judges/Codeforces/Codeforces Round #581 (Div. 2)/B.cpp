#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, l, r;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    ll mi = 0, ma = 0;
    for (int i = 1; i <= l; ++i) mi += pow(2, i - 1);
    mi += n - l;
    for (int i = 1; i <= r; ++i) {
        ma += pow(2, i - 1);
        if (i == r) ma += 1ll * pow(2, i - 1) * (n - r);
    }
    cout << mi << ' ' << ma << '\n';

    return 0;
}