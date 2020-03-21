#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];
char ans[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) ans[i] = '0';
    int l = 1, r = len;
    while (l < r) {
        if (s[l] == s[r]) {
            ans[l] = s[l];
            ans[r] = s[r];
            ++l, --r;
        } else {
            if (s[l + 1] == s[r]) {
                ans[l + 1] = s[l + 1];
                ans[r] = s[r];
                l += 2;
                --r;
            } else if (s[r - 1] == s[l]) {
                ans[r - 1] = s[r - 1];
                ans[l] = s[l];
                ++l;
                r -= 2;
            } else if (s[l + 1] == s[r - 1]) {
                ans[r - 1] = s[r - 1];
                ans[l + 1] = s[l + 1];
                l += 2;
                r -= 2;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= len; ++i)
        if (ans[i] != '0') ++cnt;
    if (!cnt) printf("%c", s[1]);
    for (int i = 1; i <= len; ++i)
        if (ans[i] != '0') printf("%c", ans[i]);

    return 0;
}