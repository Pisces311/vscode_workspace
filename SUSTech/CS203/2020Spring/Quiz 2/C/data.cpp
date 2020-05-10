#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("SUSTech/CS203/2020Spring/Quiz 2/C/Input/7.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int n = rint(1, 1000), l = rint(1, 1e6), p = rint(1, l / 2);
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        int dis = rint(1, l), fuel = rint(1, 80);
        cout << dis << ' ' << fuel << '\n';
    }
    cout << l << ' ' << p << '\n';

    return 0;
}