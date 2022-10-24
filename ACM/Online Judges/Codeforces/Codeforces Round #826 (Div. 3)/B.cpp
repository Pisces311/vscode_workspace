#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "-1\n";
            continue;
        }
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        if (n & 1) {
            for (int i = 3; i <= n; i++) {
                a[i] = i - 2;
            }
            a[1] = n;
            a[2] = n - 1;
        } else {
            for (int i = 1; i <= n; i += 2) {
                swap(a[i], a[i + 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}