#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int t, n;
int a[maxn], num[maxn];

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        fill(num, num + 101, 0);
        for (int i = 1; i <= n; ++i) ++num[a[i]];
        int amex = -1, bmex = -1;
        for (int i = 0; i <= 100; ++i) {
            if (num[i] < 2 && amex == -1) amex = i;
            if (!num[i] && bmex == -1) bmex = i;
        }
        cout << amex + bmex << '\n';
    }

    return 0;
}