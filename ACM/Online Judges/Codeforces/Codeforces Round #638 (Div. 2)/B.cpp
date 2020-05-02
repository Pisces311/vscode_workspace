#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int t, k, n;
int a[maxn];
set<int> s;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        s.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            if (s.find(a[i]) == s.end()) s.insert(a[i]);
        }
        if (s.size() > k)
            cout << "-1\n";
        else {
            cout << k * n << '\n';
            for (int i = 1; i <= n; ++i) {
                for (int j : s) cout << j << ' ';
                int tmp = k - s.size();
                while (tmp--) cout << *s.begin() << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}