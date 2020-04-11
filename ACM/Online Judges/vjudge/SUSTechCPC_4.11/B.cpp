#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;

int n;
int ok[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            ok[j] = i;
        }
    }
    sort(ok + 2, ok + n + 1);
    for (int i = 2; i <= n; ++i) cout << (ok[i] ? ok[i] : 1) << ' ';
    cout << '\n';

    return 0;
}
