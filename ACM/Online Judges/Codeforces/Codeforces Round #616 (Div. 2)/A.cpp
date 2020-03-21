#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e3 + 5;

int t, n;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> (s + 1);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int num = s[i] - '0';
            if (num & 1) ++cnt;
        }
        if (cnt >= 2) {
            int ret = 0;
            for (int i = 1; i <= n; ++i) {
                int num = s[i] - '0';
                if (num & 1) {
                    ++ret;
                    cout << num;
                    if (ret == 2) break;
                }
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}