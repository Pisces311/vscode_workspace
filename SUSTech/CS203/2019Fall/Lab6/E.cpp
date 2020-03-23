#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1e5 + 5;

int slen, plen;
set<ull> strs;
char s[maxn], p[maxn];
ull pw[maxn];

ull BKDRHash(const char *str, int l, int r) {
    ull seed = 131;
    ull hash = 0;
    for (int i = l; i <= r; ++i) hash = hash * seed + str[i];
    return (hash & 0xFFFFFFFFFFFFFFFF);
}

bool check(int mid) {
    strs.clear();
    ull hash;
    strs.insert(hash = BKDRHash(s, 0, mid - 1));
    for (int i = 1; i < slen - mid + 1; ++i) {
        hash = (hash - s[i - 1] * pw[mid - 1]) * 131 + s[i + mid - 1];
        strs.insert(hash);
    }
    if (strs.find(hash = BKDRHash(p, 0, mid - 1)) != strs.end()) return true;
    for (int i = 1; i < plen - mid + 1; ++i) {
        hash = (hash - p[i - 1] * pw[mid - 1]) * 131 + p[i + mid - 1];
        if (strs.find(hash) != strs.end()) return true;
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> p;
    slen = strlen(s), plen = strlen(p);
    pw[0] = 1;
    for (int i = 1; i <= 1e5; ++i) pw[i] = pw[i - 1] * 131;
    int l = 1, r = min(slen, plen), ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << '\n';

    return 0;
}