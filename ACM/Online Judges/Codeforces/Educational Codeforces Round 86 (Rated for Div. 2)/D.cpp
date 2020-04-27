#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, k, ans = 1;
vector<int> v[maxn];
int cnt[maxn];
multiset<int> s;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        s.insert(-a);
    }
    cnt[k] = n + 1;
    for (int i = k - 1; i >= 0; --i) cin >> cnt[i];
    while (!s.empty()) {
        int t = upper_bound(cnt, cnt + k + 1, v[ans].size()) - cnt;
        if (t == k) {
            ++ans;
        } else {
            auto i = s.lower_bound(-(k - t));
            if (i != s.end()) {
                v[ans].push_back(-(*i));
                s.erase(i);
            } else
                ++ans;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= ans; ++i) {
        cout << v[i].size() << ' ';
        for (int j : v[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}