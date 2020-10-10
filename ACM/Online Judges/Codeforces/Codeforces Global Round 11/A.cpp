#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e1 + 5;

int n, tot;
int a[maxn];
vector<int> ans;

bool check() {
    for (int i = 1; i <= n; ++i)
        if (a[i] < 0) {
            if (tot + a[i] == 0) {
                ans.clear();
                return false;
            } else {
                tot += a[i];
                ans.push_back(a[i]);
            }
        }
    for (int i = 1; i <= n; ++i)
        if (!a[i]) ans.push_back(a[i]);
    return true;
}

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
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ans.clear();
        if (!accumulate(a + 1, a + n + 1, 0))
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                if (a[i] > 0) ans.push_back(a[i]);
            tot = accumulate(ans.begin(), ans.end(), 0);
            if (check()) {
                for (int i : ans) cout << i << ' ';
                cout << '\n';
            } else {
                for (int i = 1; i <= n; ++i)
                    if (a[i] < 0) ans.push_back(a[i]);
                for (int i = 1; i <= n; ++i)
                    if (a[i] > 0) ans.push_back(a[i]);
                for (int i = 1; i <= n; ++i)
                    if (!a[i]) ans.push_back(a[i]);
                for (int i : ans) cout << i << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}