#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int w, n, k;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        sort(s, s + n);
        if (s[0] != s[k - 1])
            cout << s[k - 1];
        else if (s[k] != s[n - 1]) {
            for (int i = k - 1; i < n; ++i) cout << s[i];
        } else {
            for (int i = 0; i < n; i += k) cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}