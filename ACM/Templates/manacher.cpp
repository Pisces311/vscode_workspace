#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

char s[maxn];
char s_new[maxn << 1];
// 以p[i]为中心的新串最长回文半径，包含自己。p[i]-1即为原串回文长度。
int p[maxn << 1];

void init() {
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 1;
    for (int i = 0; i < len; ++i) {
        s_new[++j] = s[i];
        s_new[++j] = '#';
    }
    s_new[++j] = '\0';
}

int manacher() {
    init();
    int len = strlen(s_new), max_len = -1, id, mx = 0;
    for (int i = 1; i < len; ++i) {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]]) ++p[i];
        if (mx < i + p[i]) {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}