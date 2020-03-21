#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t;
ll A, B;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> A >> B;
        ll cnt = 0;
        for (int i = 10; i <= 1000000000; i *= 10) {
            if (B >= i - 1) ++cnt;
        }
        cout << cnt * A << '\n';
    }

    return 0;
}