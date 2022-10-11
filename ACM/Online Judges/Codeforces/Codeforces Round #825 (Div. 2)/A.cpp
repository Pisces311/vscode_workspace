#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int one = 0, diff = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) diff++;
            if (a[i] == 0 && b[i] == 1) {
                one++;
            } else if (a[i] == 1 && b[i] == 0) {
                one--;
            }
        }
        cout << abs(one) + (diff - abs(one) != 0) << endl;
    }
    return 0;
}