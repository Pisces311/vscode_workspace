#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 10;

int T, n;
char s[maxn], t[maxn];
int scnt[maxn], tcnt[maxn], dif[maxn];

inline void init(int n) {
    memset(scnt, 0, sizeof(int) * (n + 5));
    memset(tcnt, 0, sizeof(int) * (n + 5));
    memset(dif, 0, sizeof(int) * (n + 5));
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> (s + 1) >> (t + 1);
        s[n + 1] = t[n + 1] = '0';
        init(n);
        for (int i = 1; i <= n; ++i) {
            scnt[i] = scnt[i - 1];
            tcnt[i] = tcnt[i - 1];
            if (s[i] == '1') ++scnt[i];
            if (t[i] == '1') ++tcnt[i];
        }
        for (int i = n; i >= 1; --i) {
            dif[i] = dif[i + 1];
            if (s[i] != t[i]) ++dif[i];
        }
        int ans = dif[1];
        for (int i = 1; i <= n; ++i) {
            int cur = dif[i + 1];
            if (s[i] == '1') ++cur;
            cur += i - 1 - scnt[i - 1];
            cur += 1;
            cur += tcnt[i - 1];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}
/*
9
011111011
110000100
*/



/*
5
6
1
4
2
3
5
0
1
0
*/