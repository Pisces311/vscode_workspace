#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
char b[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> (b + 1);
        for (int i = 1; i <= n; ++i) {
            if (b[i - 1] == b[i] + 1)
                cout << '0';
            else {
                cout << '1';
                b[i] += 1;
            }
        }
        cout << '\n';
    }

    return 0;
}