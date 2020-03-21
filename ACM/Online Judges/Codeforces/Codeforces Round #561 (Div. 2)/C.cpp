#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

int n;
ll ans = 0;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a + 1, a + n + 1);
    up(i, 1, n) ans +=
        (upper_bound(a + i + 1, a + n + 1, 2 * a[i]) - (a + i + 1));
    cout << ans << endl;

    return 0;
}