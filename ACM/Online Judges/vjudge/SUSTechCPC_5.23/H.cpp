#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int len;
char s[maxn], t[maxn];
int num[4][4];
map<char, int> m;

inline void init() {
    m['A'] = 0;
    m['T'] = 1;
    m['C'] = 2;
    m['G'] = 3;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin >> (s + 1) >> (t + 1);
    len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
        if (s[i] != t[i]) {
            ++num[m[s[i]]][m[t[i]]];
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                while (num[i][j] && num[j][i]) {
                    --num[i][j];
                    --num[j][i];
                    ++ans;
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (i != j && j != k && k != i) {
                    while (num[i][j] && num[j][k] && num[k][i]) {
                        ans += 2;
                        --num[i][j];
                        --num[j][k];
                        --num[k][i];
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 4; ++i) cnt += accumulate(num[i], num[i] + 4, 0);
    ans += cnt / 4 * 3;
    cout << ans << '\n';

    return 0;
}