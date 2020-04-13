#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e1 + 5;

int t;
char g[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        for (int i = 1; i <= 9; ++i) cin >> (g[i] + 1);
        for (int i = 1; i <= 9; i += 3) {
            for (int j = i, k = i / 3 + 1; j <= i + 2; ++j, k += 3) {
                if (g[j][k] != '9')
                    ++g[j][k];
                else
                    --g[j][k];
            }
        }
        for (int i = 1; i <= 9; ++i) cout << (g[i] + 1) << '\n';
    }

    return 0;
}