#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;

int a, b, c, d;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c >> d;
    int Min = inf;
    Min = min(Min, abs(a + b - c - d));
    Min = min(Min, abs(a + c - b - d));
    Min = min(Min, abs(a + d - c - b));
    cout << Min << '\n';

    return 0;
}