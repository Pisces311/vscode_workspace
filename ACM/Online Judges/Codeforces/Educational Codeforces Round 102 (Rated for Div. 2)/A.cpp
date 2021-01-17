#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n, d;
int a[maxn];

bool check() {
    if (a[n] <= d)
        return true;
    else
        return a[1] + a[2] <= d;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}