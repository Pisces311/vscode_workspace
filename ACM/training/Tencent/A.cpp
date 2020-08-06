#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int a[maxn], b[maxn], fa[maxn], pos[maxn];

bool solve() {
    if (a[1] != b[1]) return false;
    int up = a[1];
    fa[a[1]] = 0;
    int l = 2, r = 1;
    for (int i = 2; i <= n; ++i) {
        r = max(r, pos[a[i]]);
        if (r == i) {
            for (int j = l; j <= r; ++j) fa[a[j]] = up;
            up = a[l];
            l = r + 1;
        }
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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) pos[b[i]] = i;
        if (solve()) {
            cout << "Yes\n";
            for (int i = 1; i <= n; ++i) cout << fa[i] << " \n"[i == n];
        } else
            cout << "No\n";
    }

    return 0;
}