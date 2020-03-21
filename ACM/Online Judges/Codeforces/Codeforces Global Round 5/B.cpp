#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, ans = 0;
int a[maxn], b[maxn], val[maxn];
bool vis[maxn];

void merge_sort(int l, int r) {
    if (r > l) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        int i = l;
        int p = l, q = mid + 1;
        while (p <= mid || q <= r) {
            if (q > r || (p <= mid && val[a[p]] <= val[a[q]]))
                b[i++] = a[p++];
            else {
                b[i++] = a[q++];
                if (mid - p + 1 && !vis[a[q - 1]]) {
                    ++ans;
                    vis[a[q - 1]] = true;
                }
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
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        val[v] = i;
    }
    merge_sort(1, n);
    cout << ans << '\n';

    return 0;
}