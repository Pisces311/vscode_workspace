#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
char s[maxn];
ll val[maxn];
ll h = 0, a = 0, r = 0, d = 0;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'h')
            h += val[i];
        else if (s[i] == 'a')
            a = min(a + val[i], h);
        else if (s[i] == 'r')
            r = min(r + val[i], a);
        else if (s[i] == 'd')
            d = min(d + val[i], r);
    }
    cout << d << '\n';

    return 0;
}