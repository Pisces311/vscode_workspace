#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n;
char a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> (a + 1);
        bool flag;
        if (n & 1) {
            flag = false;
            for (int i = 1; i <= n; i += 2)
                if ((a[i] - '0') & 1) flag = true;
        } else {
            flag = true;
            for (int i = 2; i <= n; i += 2)
                if ((a[i] - '0') % 2 == 0) flag = false;
        }
        if (flag)
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}