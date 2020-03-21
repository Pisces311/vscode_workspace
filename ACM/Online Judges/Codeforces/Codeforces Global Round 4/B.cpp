#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];
int l[maxn], r[maxn];
long long ans = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int cnt = 0;
    for (int i = 2; i <= len; ++i) {
        if (s[i] == 'v' && s[i - 1] == 'v') ++cnt;
        if (s[i] == 'o') l[i] = cnt;
    }
    cnt = 0;
    for (int i = len; i >= 2; --i) {
        if (s[i] == 'v' && s[i - 1] == 'v') ++cnt;
        if (s[i] == 'o') r[i] = cnt;
    }
    for (int i = 1; i <= len; ++i) {
        if (s[i] == 'o') ans += 1ll * l[i] * r[i];
    }
    printf("%lld\n", ans);

    return 0;
}