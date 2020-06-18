#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct node {
    int id, in, out;
    bool operator<(const node& a) const {
        return out == a.out ? in > a.in : out > a.out;
    }
} a[maxn];

int T, n, m;

inline void init(int i) { a[i] = {i, 0, 0}; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) init(i);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            ++a[u].out;
            ++a[v].in;
        }
        sort(a + 1, a + n + 1);
        cout << 4 * n / 7 << '\n';
        for (int i = 1; i <= 4 * n / 7; ++i) cout << a[i].id << ' ';
        cout << '\n';
    }

    return 0;
}