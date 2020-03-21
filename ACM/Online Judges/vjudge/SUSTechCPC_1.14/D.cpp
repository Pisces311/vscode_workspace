#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll k, x;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> k >> x;
        if (x == 1) {
            cout << 10 - k << '\n';
            continue;
        }
        ll s = k;
        int count = 1;
        while (x) {
            if (x - s <= 0) break;
            x -= s;
            s *= k;
            count++;
        }
        int t = 10 - k, st[110], cnt = 0;
        x--;
        while (x) {
            st[++cnt] = x % k;
            x /= k;
        }
        for (int i = 0; i < count - cnt; i++) cout << t;
        for (int i = cnt; i >= 1; i--) {
            cout << st[i] + t;
        }
        cout << '\n';
    }

    return 0;
}