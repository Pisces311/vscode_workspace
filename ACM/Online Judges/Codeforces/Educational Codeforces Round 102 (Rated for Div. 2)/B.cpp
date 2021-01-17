#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e1 + 5;

int slen, tlen;
char s[maxn], t[maxn];

int get() {
    int cnt = 1;
    for (int i = 0, j = 0;;) {
        if (s[i] == t[j]) {
            ++i, ++j;
            if (i == slen && j == tlen) {
                return cnt;
            } else if (i == slen) {
                i = 0;
                ++cnt;
                if (cnt > 21) return -1;
            } else if (j == tlen)
                j = 0;
        } else
            return -1;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        cin >> s >> t;
        slen = strlen(s), tlen = strlen(t);
        int ret = get();
        if (ret == -1)
            cout << ret << '\n';
        else {
            for (int i = 1; i <= ret; ++i) cout << s;
            cout << '\n';
        }
    }

    return 0;
}