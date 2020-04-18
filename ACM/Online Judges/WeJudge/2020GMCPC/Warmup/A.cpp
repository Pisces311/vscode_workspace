#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, a, b, c;

int type(int x, int y, int z) {
    int num = 0x3f3f3f3f;
    if (x) num = min(num, a / x);
    if (y) num = min(num, b / y);
    if (z) num = min(num, c / z);
    a -= x * num;
    b -= y * num;
    c -= z * num;
    return num;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> a >> b >> c;
        int ans = 0;
        ans += type(1, 2, 1);
        ans += type(3, 1, 1);
        ans += type(5, 0, 1);
        ans += type(1, 4, 0);
        ans += type(3, 3, 0);
        ans += type(5, 2, 0);
        ans += type(7, 1, 0);
        ans += type(9, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}