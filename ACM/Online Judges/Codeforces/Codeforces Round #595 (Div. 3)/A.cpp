#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int q, n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        bool ok = true;
        for (int i = 2; i <= n; ++i)
            if (a[i] - a[i - 1] == 1) ok = false;
        if (ok)
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}