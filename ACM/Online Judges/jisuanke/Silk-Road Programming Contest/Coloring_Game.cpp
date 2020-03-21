#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const ll mod = 1e9 + 7;

int n;
ll ans;

ll power(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x;
            res = res % mod;
        }
        x = x * x;
        x = x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ans = power(3, n - 2);
    ans = (ans * 4) % mod;
    cout << ans << endl;

    return 0;
}