#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
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
        cin >> n;
        cin >> (s + 1);
        int pre0 = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '0') {
                cout << '0';
                pre0 = i;
            } else
                break;
        }
        for (int i = n; i >= pre0 + 1; --i) {
            if (s[i] == '0') {
                pre0 = i;
                cout << '0';
                break;
            }
        }
        for (int i = pre0 + 1; i <= n; ++i) cout << '1';
        cout << '\n';
    }

    return 0;
}