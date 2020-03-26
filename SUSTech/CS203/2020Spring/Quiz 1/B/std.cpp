#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, f, w, s;

bool check(int mid) {
    return f >= mid && w >= mid && (f - mid) + (w - mid) + s >= mid;
}

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/B/Input/test4.in", "r", stdin);
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/B/Output/test4.out", "w",
            stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> f >> w >> s;
        int l = 0, r = 1e8, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}