#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll n, m, sx, sy, nx, ny;
int q;
long double s;

ll gcd(ll a, ll b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    ll d = gcd(n, m);
    ll div1 = n / d;
    ll div2 = m / d;
    while (q--) {
        cin >> sx >> sy >> nx >> ny;
        ll id1, id2;
        bool fl = 0;
        if (sx == 1 && nx == 1) {
            id1 = (sy - 1) / div1;
            id2 = (ny - 1) / div1;
        } else if (sx == 1 && nx == 2) {
            id1 = (sy - 1) / div1;
            id2 = (ny - 1) / div2;

        } else if (sx == 2 && nx == 1) {
            id1 = (sy - 1) / div2;
            id2 = (ny - 1) / div1;
        } else {
            id1 = (sy - 1) / div2;
            id2 = (ny - 1) / div2;
        }
        fl = (id1 == id2);
        cout << (fl ? "YES" : "NO") << '\n';
    }

    return 0;
}