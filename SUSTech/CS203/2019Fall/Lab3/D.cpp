#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
int a[maxn], b[maxn];
ll ans = 0;

void merge_sort(int l, int r) {
    if (r > l) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        int i = l;
        int p = l, q = mid + 1;
        ll lsum = 0;
        for (int i = l; i <= mid; ++i) lsum += a[i];
        while (p <= mid || q <= r) {
            if (q > r || (p <= mid && a[p] <= a[q])) {
                b[i++] = a[p];
                lsum -= a[p++];
            } else {
                b[i++] = a[q];
                ans += 1ll * a[q++] * (mid - p + 1) + lsum;
            }
        }
        for (i = l; i <= r; ++i) a[i] = b[i];
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    merge_sort(1, n);
    cout << ans << '\n';

    return 0;
}