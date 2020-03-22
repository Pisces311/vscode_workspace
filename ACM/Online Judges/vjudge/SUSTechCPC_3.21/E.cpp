#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct stone {
    ll id;
    int magic;
    bool operator<(const stone& other) const { return magic > other.magic; }
} s[maxn];

int n;
ll d[60];

void insert(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else {
                d[i] = val;
                break;
            }
        }
    }
}

bool check(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else
                break;
        }
    }
    return val > 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i].id >> s[i].magic;
    sort(s + 1, s + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (check(s[i].id)) {
            ans += s[i].magic;
            insert(s[i].id);
        }
    }
    cout << ans << '\n';

    return 0;
}