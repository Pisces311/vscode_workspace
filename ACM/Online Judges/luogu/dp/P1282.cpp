#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct card {
    int w, v;
} a[maxn];

int n;
int dp[6005];
bool vs[1005][6005];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int base = 0, V = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            a[i] = {1, 2 * (x - y)};
            V += x - y;
        } else if (y > x) {
            a[i] = {-1, 2 * (y - x)};
            V += y - x;
            ++base;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= 1; --j) {
            vs[i][j] = vs[i - 1][j];
            if (vs[i - 1][j - a[i].v] || j - a[i].v == 0) {
                if (!vs[i][j]) {
                    dp[j] = dp[j - a[i].v] + a[i].w;
                    vs[i][j] = 1;
                } else
                    dp[j] = min(dp[j], dp[j - a[i].v] + a[i].w);
            }
        }
    }
    for (int i = V; i >= 1; i--)
        if (vs[n][i]) {
            cout << base + dp[i];
            break;
        }

    return 0;
}