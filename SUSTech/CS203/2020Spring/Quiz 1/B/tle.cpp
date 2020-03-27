#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, f, w, s;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> f >> w >> s;
        int ans = 0;
        while (f > 0 && w > 0 && s > 0) {
            --f;
            --w;
            --s;
            ++ans;
        }
        while (f > 0 && w > 0) {
            --f;
            --w;
            if (f > w)
                --f;
            else
                --w;
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}