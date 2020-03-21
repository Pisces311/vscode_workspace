#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int n = 400000;
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        int num = rint(1, 1000000000);
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}