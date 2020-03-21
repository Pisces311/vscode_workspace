#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e1 + 5;

int T;
char s[maxn];

ll parsell(int st, int ed) {
    ll ret = 0, base = 1;
    for (int i = ed; i >= st; --i) {
        ret += (s[i] - '0') * base;
        base *= 10;
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> (s + 1);
        int len = strlen(s + 1);
        ll ma = LLONG_MIN;
        for (int i = 1; i < len - 3; ++i) {
            ll a = parsell(1, i);
            for (int j = i + 1; j < len - 2; ++j) {
                ll b = parsell(i + 1, j);
                for (int k = j + 1; k < len - 1; ++k) {
                    ll c = parsell(j + 1, k);
                    for (int l = k + 1; l < len; ++l) {
                        ll d = parsell(k + 1, l);
                        ll e = parsell(l + 1, len);
                        ma = max(ma, a + b - c * d / e);
                    }
                }
            }
        }
        cout << ma << '\n';
    }

    return 0;
}