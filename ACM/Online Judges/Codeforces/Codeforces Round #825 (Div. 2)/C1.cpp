#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int left = 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int cur = i - a[i] + 1;
            left = max(left, cur);
            ans += i - left + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}