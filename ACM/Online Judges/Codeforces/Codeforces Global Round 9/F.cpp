#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll d, k, t;
ll pile[4];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 3; ++i) cin >> pile[i];
    cout << "First\n";
    d = 0x3f3f3f3f;
    cout << d << endl;
    cin >> k;
    pile[k] += d;
    t = 3 * pile[k] - accumulate(pile + 1, pile + 4, 0ll);
    cout << t << endl;
    cin >> k;
    pile[k] += t;
    cout << (*max_element(pile + 1, pile + 4) -
             *min_element(pile + 1, pile + 4)) /
                2
         << endl;
    cin >> k;

    return 0;
}
