#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 5;

struct node {
    int val, id;
    bool operator<(const node &a) const { return val < a.val; }
} a[maxn];

int n;
int pre[maxn], nxt[maxn], ans[maxn], num[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
        num[i] = a[i].val;
    }
    sort(a + 1, a + n + 1);
    num[0] = -2e9;
    num[n + 1] = 2e9;
    for (int i = 1; i <= n + 1; ++i) {
        nxt[a[i - 1].id] = a[i].id;
        pre[a[i].id] = a[i - 1].id;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = min(abs(num[i] - num[nxt[i]]), abs(num[i] - num[pre[i]]));
        pre[nxt[i]] = pre[i];
        nxt[pre[i]] = nxt[i];
    }
    for (int i = 1; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}