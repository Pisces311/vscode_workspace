#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int N, S;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    if (N * 2 > S)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i < N; ++i) cout << 2 << ' ';
        cout << S - 2 * (N - 1) << '\n';
        cout << 1 << '\n';
    }

    return 0;
}