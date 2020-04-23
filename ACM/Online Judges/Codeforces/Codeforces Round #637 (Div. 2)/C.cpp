#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
int p[maxn], pos[maxn];

bool check(int l, int r, int base) {
    if (l > r) return false;
    for (int i = l, cnt = 1; i <= r; ++i, ++cnt)
        if (p[i] != base + cnt) return false;
    return true;
}

bool solve() {
    int tot = n;
    while (tot) {
        int base = n - tot;
        int l = tot - (p[tot] - base) + 1, r = tot;
        if (!check(l, r, base)) return false;
        tot = tot - (p[tot] - base);
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

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i];
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}