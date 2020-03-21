#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, k;
vector<int> a[110000];

void solve() {
    if (1ll * (1 + n) * n / 2 % k) {
        cout << "no" << '\n';
        return;
    }
    cout << "yes" << '\n';
    if ((n / k) & 1) {
        if (k == 1)
            for (int i = 1; i <= n; i++) a[0].push_back(i);
        else {
            for (int i = 0; i < k; i++) a[i].push_back(i + 1);
            for (int i = 0; i < k; i++)
                if (i & 1)
                    a[i].push_back(2 * k - i / 2);
                else
                    a[i].push_back(k + 1 + k / 2 - i / 2);
            for (int i = 0; i < k; i++)
                a[i].push_back(1ll * 3 * (1 + 3 * k) / 2 - a[i][0] - a[i][1]);
            for (int i = 3 * k + 1; i <= n; i++) a[(i - 1) % k].push_back(i);
            for (int i = 3; i < n / k; i += 2)
                for (int j = 0; j * 2 < k; j++) swap(a[j][i], a[k - 1 - j][i]);
        }
    } else {
        for (int i = 1; i <= n; i++) a[(i - 1) % k].push_back(i);
        for (int i = 0; i < n / k; i += 2)
            for (int j = 0; j * 2 < k; j++) swap(a[j][i], a[k - 1 - j][i]);
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << "\n "[j < a[i].size() - 1];
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < k; i++) a[i].clear();
        solve();
    }

    return 0;
}