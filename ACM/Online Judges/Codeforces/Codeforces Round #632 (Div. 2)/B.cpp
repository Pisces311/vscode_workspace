#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
int a[maxn], b[maxn];

bool solve() {
    int pos1 = n, posn1 = n;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            pos1 = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            posn1 = i;
            break;
        }
    }
    for (int i = 1; i <= pos1; ++i)
        if (a[i] < b[i]) return false;
    for (int i = 1; i <= posn1; ++i)
        if (a[i] > b[i]) return false;
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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        if (solve()) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }

    return 0;
}