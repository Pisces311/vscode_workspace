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

const int maxn = 1e5 + 5;

struct node {
    int l, r;
    int len;
    bool operator<(const node& a) const { return len > a.len; }
} a[maxn];

int n;
ll ans = 0, ans2 = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i].l >> a[i].r;
    up(i, 1, n) a[i].len = a[i].l - a[i].r;
    sort(a + 1, a + n + 1);
    up(i, 1, n) ans += 1ll * (i - 1) * a[i].l + 1ll * (n - i) * a[i].r;
    up(i, 1, n) a[i].len = a[i].r - a[i].l;
    sort(a + 1, a + n + 1);
    up(i, 1, n) ans2 += 1ll * (i - 1) * a[i].l + 1ll * (n - i) * a[i].r;
    cout << min(ans, ans2) << endl;

    return 0;
}