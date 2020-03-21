#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, r, row[maxn * 3], col[maxn * 3], res;

struct node {
    int x, y;
    bool operator<(const node& a) const { return x > a.x; }
} a[maxn], w[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; ++i) ++row[a[i].x];
    for (int i = 0; i < maxn; ++i)
        w[i].x = row[i] + row[i + r] + row[i + 2 * r], w[i].y = i;
    sort(w, w + maxn);
    for (int i = 0; i <= 100; i++) {
        memset(col, 0, sizeof(col));
        for (int j = 0; j < n; j++)
            if (a[j].x != w[i].y && a[j].x != w[i].y + r &&
                a[j].x != w[i].y + 2 * r)
                col[a[j].y]++;
        int my = 0;
        for (int j = 0; j < maxn; j++)
            my = max(my, col[j] + col[j + r] + col[j + 2 * r]);
        res = max(res, my + w[i].x);
    }
    cout << res << '\n';

    return 0;
}