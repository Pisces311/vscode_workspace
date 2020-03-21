#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
char s[10], ans;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j) {
                cin >> s;
                if (i == 2 && j == 2) ans = s[0];
            }
        cout << ans << '\n';
    }

    return 0;
}