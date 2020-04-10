#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int p[maxn], c[maxn];

bool solve() {
    for (int i = 1; i <= n; ++i) {
        if (p[i] < p[i - 1] || c[i] < c[i - 1] ||
            p[i] - p[i - 1] < c[i] - c[i - 1] || p[i] < c[i])
            return false;
    }
    return true;
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
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i] >> c[i];
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}