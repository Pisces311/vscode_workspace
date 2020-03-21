#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, m;
int a[maxn], b[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) cin >> b[i];
        if (n <= m)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}