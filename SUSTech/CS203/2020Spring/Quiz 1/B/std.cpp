#include <assert.h>

#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, f, w, s;

bool check(int mid) {
    return f >= mid && w >= mid && (f - mid) + (w - mid) + s >= mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    assert(T <= 1e4);
    while (T--) {
        cin >> f >> w >> s;
        assert(f <= 1e8 && w <= 1e8 && s <= 1e8);
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