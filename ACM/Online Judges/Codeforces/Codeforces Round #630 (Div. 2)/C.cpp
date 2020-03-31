#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n, k;
char s[maxn], ans[maxn];
int cnt[maxn][30];

inline void init() {
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= 26; ++j) cnt[i][j] = 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> (s + 1);
        init();
        int seg = n / k;
        for (int i = 1; i <= k; ++i)
            for (int j = i; j <= n; j += k) ++cnt[i][s[j] - 'a' + 1];
        for (int i = 1; i <= (k + 1) / 2; ++i) {
            int Max = 0;
            for (int j = 1; j <= 26; ++j) {
                int num = cnt[i][j] + cnt[k - i + 1][j];
                if (Max < num) {
                    Max = num;
                    ans[i] = ans[k - i + 1] = 'a' - 1 + j;
                }
            }
        }
        for (int i = 1, id = 1; i <= seg; ++i)
            for (int j = 1; j <= k; ++j, ++id) ans[id] = ans[j];
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (s[i] != ans[i]) ++cnt;
        cout << cnt << '\n';
    }

    return 0;
}