#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int t, n, a, b;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        for (int i = 1; i <= b; ++i) s[i] = 'a' - 1 + i;
        for (int i = b + 1; i <= a; ++i) s[i] = s[i - 1];
        for (int i = a + 1; i <= n; ++i) s[i] = s[i - a];
        for (int i = 1; i <= n; ++i) cout << s[i];
        cout << '\n';
    }

    return 0;
}