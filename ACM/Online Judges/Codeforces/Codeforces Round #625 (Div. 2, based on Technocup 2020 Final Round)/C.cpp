#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n;
char s[maxn];
bool vis[maxn];
vector<int> pos[30];
bool ok;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> (s + 1);
    for (int i = 1; i <= n; ++i) pos[s[i] - 'a' + 1].push_back(i);
    int ans = 0;
    for (int i = 26; i >= 1; --i) {
        char cur = 'a' - 1 + i;
        do {
            ok = false;
            for (int j : pos[i]) {
                if (vis[j]) continue;
                int l = j - 1, r = j + 1;
                while (l != 0 && vis[l]) --l;
                while (r != n + 1 && vis[r]) ++r;
                if (cur - s[l] == 1 || cur - s[r] == 1) {
                    ans += 1;
                    vis[j] = true;
                    ok = true;
                }
            }
        } while (ok);
    }
    cout << ans << '\n';

    return 0;
}