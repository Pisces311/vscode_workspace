#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int q, a, b, n, S;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> a >> b >> n >> S;
        int res = S / n;
        if (S - min(res, a) * n <= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}