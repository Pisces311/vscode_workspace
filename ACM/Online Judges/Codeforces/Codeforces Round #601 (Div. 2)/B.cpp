#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e3 + 5;

struct node {
    int id, val;
} a[maxn];

int T, n, m;
vector<pii> v;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        v.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].val;
            a[i].id = i;
        }
        if (m < n || n == 2) {
            cout << "-1\n";
            continue;
        }
        sort(a + 1, a + n + 1, [](node &a, node &b) { return a.val < b.val; });
        int ans = 0;
        for (int i = 1; i <= n - 1; ++i) {
            ans += a[i].val + a[i + 1].val;
            v.push_back(make_pair(a[i].id, a[i + 1].id));
        }
        ans += a[n].val + a[1].val;
        v.push_back(make_pair(a[n].id, a[1].id));
        for (int i = n + 1; i <= m; ++i) {
            ans += a[1].val + a[2].val;
            v.push_back(make_pair(a[1].id, a[2].id));
        }
        cout << ans << '\n';
        for (pii p : v) cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}