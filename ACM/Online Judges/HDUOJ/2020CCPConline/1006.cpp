#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e2 + 5;

int n;
int k[maxn];
int c[maxn][maxn], b[maxn][maxn], d[maxn][maxn], a[maxn][maxn];

int output(int t, int x) {
    while (t != n) {
        int id = lower_bound(a[t], a[t] + k[t], x) - a[t];
        x = c[t][id] * x + b[t][id];
        t = d[t][id];
    }
    return x;
}

bool continues() {
    for (int i = 1; i < n; ++i) {
        int t = i;
        for (int j = 0; j < k[t]; ++j) {
            int x = a[t][j];
            int pre = c[t][j] * x + b[t][j];
            int nxt = c[t][j + 1] * x + b[t][j + 1];
            if (output(d[t][j], pre) != output(d[t][j + 1], nxt)) return false;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> n;
        for (int i = 1; i < n; ++i) {
            cin >> k[i];
            for (int j = 0; j < k[i]; ++j)
                cin >> c[i][j] >> b[i][j] >> d[i][j] >> a[i][j];
            cin >> c[i][k[i]] >> b[i][k[i]] >> d[i][k[i]];
        }
        if (continues())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}