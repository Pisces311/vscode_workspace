#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;

int t, n, k;
int a[maxn];
int pre[maxn], nxt[maxn], pos[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
            nxt[a[i - 1]] = a[i];
            pre[a[i]] = a[i - 1];
        }
        pos[n + 1] = n + 1;
        nxt[a[n]] = n + 1;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i, r = i, cnt = 1;
            ll sum = 0;
            while (cnt < k && pre[l]) l = pre[l], ++cnt;
            while (cnt < k && nxt[r] != n + 1) r = nxt[r], ++cnt;
            if (cnt < k) continue;
            for (; l != nxt[i] && r != n + 1; l = nxt[l], r = nxt[r]) {
                int l1 = pos[l] - pos[pre[l]];
                int r1 = pos[nxt[r]] - pos[r];
                sum += l1 * r1;
            }
            pre[nxt[i]] = pre[i];
            nxt[pre[i]] = nxt[i];
            ans += sum * i;
        }
        cout << ans << '\n';
    }

    return 0;
}