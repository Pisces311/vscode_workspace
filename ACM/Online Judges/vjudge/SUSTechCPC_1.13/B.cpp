#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll p, k;
vector<ll> ans;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> p >> k;
    bool pos = true;
    while (p >= k || !pos) {
        ll rem = p % k;
        ll quo = p / k;
        if (!pos && rem) {
            quo += 1;
            rem = quo * k - p;
        }
        ans.push_back(rem);
        p = quo;
        pos = !pos;
    }
    ans.push_back(p);
    cout << ans.size() << '\n';
    for (ll i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}