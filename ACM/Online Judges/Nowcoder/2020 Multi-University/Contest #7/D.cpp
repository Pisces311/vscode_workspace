#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T;
ll n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1 || n == 24)
            cout << "Fake news!\n";
        else
            cout << "Nobody knows it better than me!\n";
    }

    return 0;
}