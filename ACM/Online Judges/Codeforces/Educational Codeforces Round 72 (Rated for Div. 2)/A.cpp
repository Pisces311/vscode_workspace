#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, str, inte, ex;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> str >> inte >> ex;
        int ma = str + ex;
        if (ma > inte) {
            int l = 0, r = ex, ans = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (str + mid > inte + ex - mid) {
                    ans = str + mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            cout << ma - ans + 1 << '\n';
        } else
            cout << 0 << '\n';
    }

    return 0;
}