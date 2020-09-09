#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;

int n;
int ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int last = 1;
    for (int i = 2; i <= n; ++i) {
        int ret1, ret2;
        cout << "? " << last << ' ' << i << endl;
        cin >> ret1;
        cout << "? " << i << ' ' << last << endl;
        cin >> ret2;
        if (ret1 > ret2) {
            ans[last] = ret1;
            last = i;
        } else {
            ans[i] = ret2;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            cout << ans[i] << ' ';
        else
            cout << n << ' ';
    cout << endl;

    return 0;
}