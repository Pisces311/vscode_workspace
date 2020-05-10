#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
char s[maxn];

ll cal(int len) { return 1ll * (1 + len) * len / 2; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        cin >> (s + 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '0') {
                int l = i, r = i + 1;
                while (r <= n && s[r] == '0') ++r;
                ans += cal(r - l);
                i = r - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}