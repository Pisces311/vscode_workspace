#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int sz;
ll X;
vector<ll> fac;
bool vis[maxn];
pair<ll, ll> ans;

void dfs(ll x, ll y, int pos) {
    if (max(ans.first, ans.second) > max(x, y)) ans = make_pair(x, y);
    for (int i = pos; i < sz; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(x * fac[i], y / fac[i], i + 1);
            vis[i] = false;
        }
    }
}

void get(ll n) {
    fac.clear();
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll tmp = 1;
            while (n % i == 0) {
                tmp *= i;
                n /= i;
            }
            fac.push_back(tmp);
        }
    }
    if (n > 1) fac.push_back(n);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> X;
    get(X);
    sz = fac.size();
    ans = make_pair(1, X);
    for (int i = 0; i < sz; ++i) {
        vis[i] = true;
        dfs(fac[i], X / fac[i], i + 1);
        vis[i] = false;
    }
    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}