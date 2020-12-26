#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n, m;
map<string, int> mp;
string s[maxn];

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
        mp.clear();
        cin >> n >> m;
        for (int i = 1; i <= n + m; ++i) cin >> s[i];
        for (int i = n + 1; i <= n + m; ++i) {
            string tmp = "";
            for (int j = 0; j < s[i].length(); ++j) {
                tmp += s[i][j];
                if (s[i][j] == '/') mp[tmp] = 1;
            }
        }
        int ans = n;
        for (int i = 1; i <= n; ++i) {
            string tmp = "";
            for (int j = 0; j < s[i].length(); ++j) {
                tmp += s[i][j];
                if (s[i][j] == '/') {
                    if (!mp[tmp])
                        mp[tmp] = 2;
                    else if (mp[tmp] == 1)
                        continue;
                    else {
                        ans--;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
