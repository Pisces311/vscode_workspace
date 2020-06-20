#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int t, n;
int a[maxn];
vector<int> even, odd;

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
        for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
        even.clear();
        odd.clear();
        for (int i = 1; i <= 2 * n; ++i) {
            if (a[i] & 1)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        int cnt = 0;
        for (int i = 1; i < odd.size(); i += 2) {
            if (cnt == n - 1) break;
            cout << odd[i] << ' ' << odd[i - 1] << '\n';
            ++cnt;
        }
        for (int i = 1; i < even.size(); i += 2) {
            if (cnt == n - 1) break;
            cout << even[i] << ' ' << even[i - 1] << '\n';
            ++cnt;
        }
    }

    return 0;
}