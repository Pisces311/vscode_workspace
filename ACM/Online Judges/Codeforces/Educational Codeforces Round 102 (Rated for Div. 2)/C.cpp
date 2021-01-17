#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int n, k;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i) a[i] = i;
        int rev = n - k + 1;
        reverse(a + k - rev + 1, a + k + 1);
        for (int i = 1; i <= k; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}