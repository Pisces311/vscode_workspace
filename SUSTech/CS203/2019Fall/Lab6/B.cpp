#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int n, m, ans = 0;
int nxt[maxn];
char s[maxn], p[maxn];

void get_next(char *p) {
    nxt[0] = 0;
    for (int q = 1, k = 0; q < m; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int KMP(char *s, char *p) {
    get_next(p);
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && p[j] != s[i]) j = nxt[j - 1];
        if (p[j] == s[i]) ++j;
        if (j == m) {
            ++cnt;
            j = 0;
        }
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

    cin >> n >> m;
    cin >> s >> p;
    cout << KMP(s, p) << '\n';

    return 0;
}