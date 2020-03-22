#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int n;
ll ans = 0;
char a[maxn];

bool check() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '(')
            ++cnt;
        else
            --cnt;
    }
    return cnt == 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (!check()) {
        cout << "-1\n";
    } else {
        int cnt = 0, pre = 0, l = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == '(')
                ++cnt;
            else if (a[i] == ')')
                --cnt;
            if (cnt == 0) {
                if (pre > 0)
                    l = i;
                else {
                    ans += i - l;
                    l = i;
                }
            }
            pre = cnt;
        }
        cout << ans << '\n';
    }

    return 0;
}