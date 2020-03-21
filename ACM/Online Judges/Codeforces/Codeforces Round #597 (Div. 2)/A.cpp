#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, a, b;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (gcd(a, b) != 1)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }

    return 0;
}