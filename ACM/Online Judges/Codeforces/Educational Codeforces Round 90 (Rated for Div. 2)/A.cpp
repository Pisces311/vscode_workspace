#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll a, b, c;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a < c)
            cout << "1 ";
        else
            cout << "-1 ";
        if (a * b > c)
            cout << b << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}