#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, p;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    int ans = -1;
    for (int i = 1; i <= 100; ++i) {
        int sum = n - i * p;
        if (sum <= 0) continue;
        int cnt = __builtin_popcount(sum);
        if (cnt <= i && i <= sum) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}