#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
char s[maxn];
char st[maxn];
int len;
int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        cin >> s;
        int a = 0, b = 0, c = 0, d = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            st[++len] = s[i];
            if (len >= 4 && st[len] == '0' && st[len - 1] == '2' &&
                st[len - 2] == '0' && st[len - 3] == '2') {
                len -= 4;
                d++;
            }
        }
        for (int i = 1; i <= len; ++i) {
            if (st[i] == '2') {
                if (b) {
                    --b, ++c;
                } else
                    ++a;
            } else if (st[i] == '0') {
                if (c) {
                    --c, ++d;
                } else if (a) {
                    --a, ++b;
                }
            }
        }
        cout << d << '\n';
    }

    return 0;
}
