#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int T, n, k, d;
int a[maxn], num[maxn], cnt, ans;

void insert(int x) {
    ++num[x];
    if (num[x] == 1) ++cnt;
}

void del(int x) {
    --num[x];
    if (!num[x]) --cnt;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> k >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cnt = 0;
        for (int i = 1; i <= d; ++i) insert(a[i]);
        ans = cnt;
        for (int i = d + 1; i <= n; ++i) {
            insert(a[i]), del(a[i - d]);
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) num[a[i]] = 0;
    }

    return 0;
}