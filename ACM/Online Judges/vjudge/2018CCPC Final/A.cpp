#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int D, T;
    bool operator<(const node& a) { return D < a.D; }
} a[maxn];

int N, M;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cas = 1; cas <= t; ++cas) {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) cin >> a[i].D;
        for (int i = 1; i <= N; ++i) cin >> a[i].T;
        sort(a + 1, a + N + 1);
        int cur = 0, ans = 0;
        for (int i = 1; i <= N; ++i) {
            cur += a[i].T;
            if (cur <= M) ++ans;
        }
        cout << "Case " << cas << ": " << ans << '\n';
    }

    return 0;
}