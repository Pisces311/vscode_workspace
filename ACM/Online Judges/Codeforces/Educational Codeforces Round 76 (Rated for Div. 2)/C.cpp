#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n;
int a[maxn], l[maxn], pos[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        int ans = inf;
        for (int i = 1; i <= n; ++i) {
            pos[i] = 0;
            l[i] = inf;
        }
        for (int i = 1; i <= n; ++i) {
            if (pos[a[i]]) l[a[i]] = min(l[a[i]], i - pos[a[i]] + 1);
            pos[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i) ans = min(ans, l[a[i]]);
        cout << (ans == inf ? -1 : ans) << '\n';
    }

    return 0;
}