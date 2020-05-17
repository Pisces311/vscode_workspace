#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 1e5 + 5;

int t;
ll a, k;

inline pii digit(ll x) {
    int Min = 10, Max = -1;
    while (x) {
        int rem = x % 10;
        Min = min(Min, rem);
        Max = max(Max, rem);
        x /= 10;
    }
    return make_pair(Min, Max);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> k;
        --k;
        while (k--) {
            pii ret = digit(a);
            if (ret.first) {
                a += ret.first * ret.second;
            } else
                break;
        }
        cout << a << '\n';
    }

    return 0;
}