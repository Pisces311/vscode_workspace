#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e4 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    bool less = false;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            if (less) {
                if (a[i] > 0)
                    a[i] = a[i] / 2 + 1;
                else
                    a[i] = a[i] / 2;
            } else {
                if (a[i] > 0)
                    a[i] = a[i] / 2;
                else
                    a[i] = a[i] / 2 - 1;
            }
            less = !less;
        } else
            a[i] /= 2;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << '\n';

    return 0;
}
