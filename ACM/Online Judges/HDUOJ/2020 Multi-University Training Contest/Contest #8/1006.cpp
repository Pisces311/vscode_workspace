#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n, k;
int l[maxn], r[maxn];
int up[maxn], down[maxn];
vector<int> ans;

bool solve() {
    int mi = -1, ma = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        mi = max(mi - k, l[i]), ma = min(ma + k, r[i]);
        if (mi > ma) return false;
        down[i] = mi, up[i] = ma;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        ans.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
        if (solve()) {
            cout << "YES\n";
            int val = up[n];
            ans.push_back(val);
            for (int i = n - 1; i >= 1; --i) {
                if (val - k <= up[i] && up[i] <= val + k)
                    val = up[i];
                else
                    val = min(up[i], val + k);
                ans.push_back(val);
            }
            for (int i = 1; i <= n; ++i) cout << ans[n - i] << " \n"[i == n];
        } else
            cout << "NO\n";
    }

    return 0;
}