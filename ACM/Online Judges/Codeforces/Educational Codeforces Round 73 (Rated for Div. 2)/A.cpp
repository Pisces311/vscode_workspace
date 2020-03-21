#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int q, n;
map<int, int> ma;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        ma.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int val;
            cin >> val;
            ++ma[val];
        }
        int base = 1;
        while (base <= 1024) {
            ma[base << 1] += ma[base] / 2;
            base <<= 1;
        }
        if (ma[2048])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}