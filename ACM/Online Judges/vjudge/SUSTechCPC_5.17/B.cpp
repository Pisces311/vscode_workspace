#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;

char s[maxn], t[maxn];
int nxt[maxn];
int zero = 0, one = 0;

void get_next(char *p) {
    nxt[0] = 0;
    int plen = strlen(p);
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    int slen = strlen(s), tlen = strlen(t);
    get_next(t);
    for (int i = 0; i < slen; ++i)
        if (s[i] == '0')
            ++zero;
        else
            ++one;
    int cur = 0;
    while (zero && one) {
        cout << t[cur];
        if (t[cur] == '0')
            --zero;
        else
            --one;
        ++cur;
        if (cur == tlen) cur = nxt[cur - 1];
    }
    while (zero--) cout << 0;
    while (one--) cout << 1;
    cout << '\n';

    return 0;
}