#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;

ll dfs(vector<ll>& a, int i) {
    if (i < 0) return 0;
    vector<ll> one, zero;
    ll num = (1LL << i);
    for (ll x : a)
        if ((x / num) & 1)
            one.push_back(x);
        else
            zero.push_back(x);
    if (!one.size()) return dfs(zero, i - 1);
    if (!zero.size()) return dfs(one, i - 1);
    return num + min(dfs(one, i - 1), dfs(zero, i - 1));
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << dfs(a, 29) << '\n';

    return 0;
}