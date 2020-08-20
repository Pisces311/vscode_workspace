#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

struct task {
    int t, id;
    bool operator<(const task& a) { return t == a.t ? id < a.id : t > a.t; }
} a[maxn];

int n, m, k;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].t;
            a[i].id = i;
        }
        if (k) {
            sort(a + 1, a + n + 1);
            for (int i = 1; i <= n; ++i) cout << a[i].id << " \n"[i == n];
        } else
            for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
    }

    return 0;
}