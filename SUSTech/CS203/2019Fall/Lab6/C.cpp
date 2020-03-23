#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int N, ans = 0;
int nxt[maxn];
char s[maxn], p[maxn];

void get_next(char *p) {
    nxt[0] = 0;
    int plen = strlen(p);
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int KMP(char *s, char *p) {
    get_next(p);
    int slen = strlen(s), plen = strlen(p);
    int cnt = 0;
    for (int i = 0, j = 0; i < slen; ++i) {
        while (j > 0 && p[j] != s[i]) j = nxt[j - 1];
        if (p[j] == s[i]) cnt = max(cnt, ++j);
        if (j == plen) j = nxt[j - 1];
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> s >> p;
        if (3 * KMP(p, s) >= (int)strlen(s)) ++ans;
    }
    cout << ans << '\n';

    return 0;
}