#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t;
char s[100];
ll n, k, x, y;
ll ans, a, b;

inline void init() {
    k = 1ll << 31;
    ans = a = b = n = x = y = 0;
}

ll get(ll a, int l, int r) {
    for (int i = l; i <= r; ++i) {
        a *= 10;
        a += s[i] - '0';
    }
    return a;
}

void dfs1(ll n, ll k) {
    k >>= 1;
    if (n == 1) {
        a += 1;
        b += 1;
        return;
    }
    if (n <= k * k) {
        dfs1(n, k);
    } else if (n <= k * k * 2) {
        dfs1(n - (k * k), k);
        a += k;
    } else if (n <= k * k * 3) {
        dfs1(n - 2 * (k * k), k);
        a += k;
        b += k;
    } else if (n <= k * k * 4) {
        dfs1(n - 3 * (k * k), k);
        b += k;
    }
}

void dfs2(ll x, ll y, ll k) {
    k >>= 1;
    if (x == 1 && y == 1) {
        ans += 1;
        return;
    }
    if (x <= k && y <= k) {
        dfs2(x, y, k);
    } else if (x >= k + 1 && y <= k) {
        dfs2(x - k, y, k);
        ans += k * k;
    } else if (x >= k + 1 && y >= k + 1) {
        dfs2(x - k, y - k, k);
        ans += 2 * k * k;
    } else if (x <= k && y >= k + 1) {
        dfs2(x, y - k, k);
        ans += 3 * k * k;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        init();
        cin >> (s + 1);
        int len = strlen(s + 1);
        if (s[1] >= '0' && s[1] <= '9') {
            n = get(n, 1, len);
            dfs1(n, k);
            cout << '(' << a << ',' << b << ")\n";
        } else {
            int pos;
            for (int i = 1; i <= len; ++i)
                if (s[i] == ',') pos = i;
            x = get(x, 2, pos - 1);
            y = get(y, pos + 1, len - 1);
            dfs2(x, y, k);
            cout << ans << '\n';
        }
    }

    return 0;
}