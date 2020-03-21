#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int t, n, a, b, c, r, s, p;
char seq[maxn], ans[maxn];

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
        cin >> a >> b >> c;
        cin >> (seq + 1);
        for (int i = 1; i <= n; ++i) ans[i] = '*';
        r = s = p = 0;
        for (int i = 1; i <= n; ++i) {
            if (seq[i] == 'R') ++r;
            if (seq[i] == 'S') ++s;
            if (seq[i] == 'P') ++p;
        }
        int win = min(a, s) + min(b, r) + min(c, p);
        if (2 * win >= n) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                if (seq[i] == 'R' && b) {
                    --b;
                    ans[i] = 'P';
                } else if (seq[i] == 'S' && a) {
                    --a;
                    ans[i] = 'R';
                } else if (seq[i] == 'P' && c) {
                    --c;
                    ans[i] = 'S';
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (ans[i] == '*') {
                    if (a) {
                        --a;
                        cout << 'R';
                    } else if (c) {
                        --c;
                        cout << 'S';
                    } else {
                        --b;
                        cout << 'P';
                    }
                } else
                    cout << ans[i];
            }
            cout << '\n';
        } else
            cout << "NO\n";
    }

    return 0;
}