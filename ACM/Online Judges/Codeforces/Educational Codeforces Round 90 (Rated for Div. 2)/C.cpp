#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int t;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        int Min = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '+')
                ++cnt;
            else
                --cnt;
            Min = min(Min, cnt);
        }
        int Max = -Min;
        Min = 0, cnt = 0;
        int floor = 0;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += Max + 1 + floor;
            if (s[i] == '+')
                ++cnt;
            else
                --cnt;
            if (cnt < floor) --floor;
        }
        cout << ans << '\n';
    }

    return 0;
}