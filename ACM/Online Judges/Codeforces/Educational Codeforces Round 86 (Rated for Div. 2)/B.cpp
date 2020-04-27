#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int T;
char t[maxn];

bool check(int len) {
    char ch = t[1];
    for (int i = 1; i <= len; ++i)
        if (t[i] != ch) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> (t + 1);
        int len = strlen(t + 1);
        if (check(len)) {
            cout << (t + 1) << '\n';
        } else {
            bool flag = true;
            for (int i = 1; i <= len; ++i) {
                if (flag) {
                    cout << '1';
                    if (t[i] != '1') --i;
                    flag = false;
                } else {
                    cout << '0';
                    if (t[i] != '0') --i;
                    flag = true;
                }
            }
            if (!flag) cout << '0';
            cout << '\n';
        }
    }

    return 0;
}