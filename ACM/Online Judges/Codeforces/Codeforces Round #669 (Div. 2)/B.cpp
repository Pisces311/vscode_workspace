#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n;
int a[maxn];
bool vis[maxn];
vector<int> ans;

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
        memset(vis, false, sizeof(vis));
        ans.clear();
        int p = max_element(a + 1, a + n + 1) - a;
        vis[p] = true;
        ans.push_back(a[p]);
        int GCD = a[p];
        for (int i = 1; i < n; ++i) {
            int ma = -1;
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    int cur = __gcd(a[j], GCD);
                    if (cur > ma) {
                        ma = cur;
                        p = j;
                    }
                }
            }
            GCD = ma;
            vis[p] = true;
            ans.push_back(a[p]);
        }
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}