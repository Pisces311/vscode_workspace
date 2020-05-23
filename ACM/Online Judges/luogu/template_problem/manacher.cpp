#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1.1e7 + 5;

char s[maxn];
char s_new[maxn << 1];
int p[maxn << 1];

int init() {
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; ++i) {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;
}

int manacher() {
    int len = init();
    int max_len = -1, id;
    int mx = 0;
    for (int i = 1; i <= len; ++i) {
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    cout << manacher() << '\n';
    
    return 0;
}