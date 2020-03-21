#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, slen, tlen;
char s[maxn], t[maxn];
int appear[maxn][30];

inline void init() {
    for (int i = 1; i <= slen + 1; ++i) {
        for (int j = 1; j <= 26; ++j) {
            appear[i][j] = 0;
        }
    }
}

int solve() {
    int ans = 1;
    for (int i = 1, j = 1; i <= tlen; ++i) {
        int p = t[i] - 'a' + 1;
        if (appear[j][p])
            j = appear[j][p] + 1;
        else if (j == 1) {
            return -1;
        } else {
            j = 1;
            --i;
            ++ans;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> (s + 1) >> (t + 1);
        slen = strlen(s + 1), tlen = strlen(t + 1);
        init();
        for (int i = slen; i >= 1; --i) {
            for (int j = 1; j <= 26; ++j) {
                appear[i][j] = appear[i + 1][j];
            }
            int p = s[i] - 'a' + 1;
            appear[i][p] = i;
        }
        cout << solve() << '\n';
    }

    return 0;
}