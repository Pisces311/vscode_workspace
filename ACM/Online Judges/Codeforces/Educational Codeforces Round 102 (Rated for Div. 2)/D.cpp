#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, m;
char op[maxn];
int a[maxn], b[maxn];
int Min[maxn][20], Max[maxn][20];

void init(int n) {
    for (int i = 1; i <= n; ++i) Min[i][0] = Max[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int qmax(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}

int qmin(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> (op + 1);
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i) {
            if (op[i] == '+')
                b[i] = b[i - 1] + 1;
            else
                b[i] = b[i - 1] - 1;
        }
        b[n + 1] = b[n];
        for (int i = 1; i <= n + 2; ++i) a[i] = b[i - 1];
        init(n + 2);
        while (m--) {
            int l, r;
            cin >> l >> r;
            ++l, ++r;
            int dif = a[r] - a[l - 1];
            int ma = max(qmax(1, l - 1), qmax(r + 1, n + 2) - dif);
            int mi = min(qmin(1, l - 1), qmin(r + 1, n + 2) - dif);
            int ans = ma - mi + 1;
            cout << ans << '\n';
        }
    }

    return 0;
}