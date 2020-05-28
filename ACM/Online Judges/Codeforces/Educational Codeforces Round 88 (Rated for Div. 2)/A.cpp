#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, m, k;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int cards = n / k;
        if (cards >= m)
            cout << m << '\n';
        else {
            int Max = ceil(1.0 * (m - cards) / (k - 1));
            cout << cards - Max << '\n';
        }
    }

    return 0;
}