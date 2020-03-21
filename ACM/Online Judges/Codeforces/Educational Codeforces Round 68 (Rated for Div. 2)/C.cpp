#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int q, slen, tlen, plen;
char s[maxn], t[maxn], p[maxn];
int cntp[30];

bool match() {
    int pos = 1;
    for (int i = 1; i <= tlen; ++i) {
        if (s[pos] == t[i])
            ++pos;
        else {
            if (cntp[t[i] - 'a' + 1]) {
                --cntp[t[i] - 'a' + 1];
            } else
                return false;
        }
    }
    if (pos != slen + 1) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%s %s %s", s + 1, t + 1, p + 1);
        memset(cntp, 0, sizeof(cntp));
        slen = strlen(s + 1), tlen = strlen(t + 1), plen = strlen(p + 1);
        if (slen > tlen) {
            printf("NO\n");
            continue;
        }
        for (int i = 1; i <= plen; ++i) ++cntp[p[i] - 'a' + 1];
        if (match())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}