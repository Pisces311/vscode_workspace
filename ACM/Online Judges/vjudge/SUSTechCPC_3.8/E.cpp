#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
ll k;
ll a[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int pos = max_element(a + 1, a + n + 1) - a;
    ll Max = a[pos];
    ll sum = accumulate(a + 1, a + n + 1, 0ll);
    ll pre = accumulate(a + 1, a + pos, 0ll);
    ll l = 0, r = 1e9;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll less = mid * (n - 1 + Max) + pos - 1;
        ll more = mid * sum + pre;
        if (k < less)
            r = mid - 1;
        else if (k > more)
            l = mid + 1;
        else {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "KEK\n";

    return 0;
}