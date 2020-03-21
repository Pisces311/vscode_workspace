#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, n;
int a[maxn], b[maxn];

bool solve() {
    for (int i = 1; i <= n; ++i) {
        b[i] -= a[i];
        if (b[i] < 0) return false;
    }
    int l = 1, r = n;
    while (!b[l]) ++l;
    while (!b[r]) --r;
    int k = b[l];
    for (int i = l; i <= r; ++i)
        if (b[i] != k) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}