#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll t, n, k, cnt, now;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cnt = 0, now = 1;
        cin >> k >> n;
        if (k == 1) {
            cout << n - 1 << endl;
            continue;
        }
        while (n > 0) {
            n -= now;
            now *= k;
            cnt++;
            if (n < now) break;
        }
        if (n == 0)
            cout << cnt * 2 - 2 << endl;
        else if (n <= now / k)
            cout << cnt * 2 - 1 << endl;
        else
            cout << cnt * 2 << endl;
    }

    return 0;
}