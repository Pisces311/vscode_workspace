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

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll res = 0, ans = 0;
    up(i, 0, n - 1) {
        ll a;
        cin >> a;
        ll mn = min(res, a / 2);
        res -= mn, a -= 2 * mn;
        ans += mn + a / 3;
        a %= 3;
        res += a;
    }
    cout << ans << endl;

    return 0;
}