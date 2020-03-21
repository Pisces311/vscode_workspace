#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

int n;
ll a;
map<ll, int> ma;

ll frac(int x) {
    ll res = 1;
    for (int i = x; i >= 1; --i) res *= i;
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        ++ma[a];
    }
    ll ans = 0;
    for (auto i : ma) {
        ans += frac(i.second);
    }
    cout << ans << endl;

    return 0;
}