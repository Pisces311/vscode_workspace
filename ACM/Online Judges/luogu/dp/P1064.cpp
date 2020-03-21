#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 32e3 + 5;

int n, m;
int dp[maxn], h[maxn];
vector<int> belong[65];

struct node {
    int v, p, q;
} a[65];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].v >> a[i].p >> a[i].q;
        a[i].p *= a[i].v;
        if (a[i].q) belong[a[i].q].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
        if (!a[i].q) {
            for (int j = 1; j < a[i].v; ++j) h[j] = 0;
            for (int j = a[i].v; j <= n; ++j) h[j] = dp[j - a[i].v] + a[i].p;
            for (int l = 0; l < belong[i].size(); ++l) {
                int j = belong[i][l];
                for (int k = n; k >= a[i].v + a[j].v; k--)
                    h[k] = max(h[k], h[k - a[j].v] + a[j].p);
            }
            for (int j = a[i].v; j <= n; ++j) dp[j] = max(dp[j], h[j]);
        }
    cout << dp[n] << '\n';

    return 0;
}