#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;

int k, n;
string s, t;

void solve() {
    vector<int> cnts(26, 0);
    for (char c : s) ++cnts[c - 'a'];
    for (char c : t) ++cnts[c - 'a'];
    for (int ele : cnts) {
        if (ele & 1) {
            cout << "No\n";
            return;
        }
    }
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        bool find = false;
        for (int j = i + 1; j < n; j++) {
            if (t[i] == t[j]) {
                ans.emplace_back(i, j);
                swap(s[i], t[j]);
                find = true;
                break;
            }
        }
        if (find) continue;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == t[i]) {
                ans.emplace_back(j, i + 1);
                swap(s[j], t[i + 1]);
                ans.emplace_back(i, i + 1);
                swap(s[i], t[i + 1]);
                break;
            }
        }
    }
    cout << "Yes\n";
    cout << ans.size() << '\n';
    for (pii p : ans) cout << p.first + 1 << " " << p.second + 1 << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    while (k--) {
        cin >> n;
        cin >> s >> t;
        solve();
    }

    return 0;
}