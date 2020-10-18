#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
ll rll(ll a, ll b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int t = 1;
    cout << t << '\n';
    while (t--) {
        int n = rint(1, 5);
        cout << n << ' ' << rint(1, 100) << '\n';
        for (int i = 1; i <= n; ++i)
            cout << rint(1, 20) << ' ' << rint(1, 20) << '\n';
    }

    return 0;
}