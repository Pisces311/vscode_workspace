#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int q, n;
int a[maxn];
bool vis[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            vis[i] = true;
        }
        int num = 0;
        while (++num <= n) {
            int pos = -1;
            for (int i = 1; i <= n; ++i)
                if (a[i] == num) {
                    pos = i;
                    break;
                }
            while (pos != 1 && vis[pos - 1]) {
                vis[pos - 1] = false;
                swap(a[pos], a[pos - 1]);
                pos -= 1;
            }
            vis[pos] = false;
        }
        for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}