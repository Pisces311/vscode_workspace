#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n, x, y;
int a[maxn];

bool solve(int n) {
    if (x > n || y > n) return false;
    int cur = n, tar = x;
    bool flag = (y == 1);
    while (cur > tar) {
        int len = min(n - x + 1, y);
        if (len == y) flag = true;
        if (n - len + 1 < 1) return false;
        reverse(a + n - len + 1, a + n + 1);
        n -= len;
        --x;
        cur -= len - 1;
    }
    return cur == tar && flag;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i) a[i] = i;
        if (solve(n)) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
        } else
            cout << "NO\n";
    }

    return 0;
}