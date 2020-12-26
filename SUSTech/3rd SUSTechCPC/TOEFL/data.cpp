#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
    freopen("./In/5.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int T = 100;
    cout << T << '\n';
    while (T--) {
        for (int i = 1; i <= 4; ++i) cout << rint(0, 30) << " \n"[i == 4];
        for (int i = 1; i <= 4; ++i) cout << rint(1, 100) << " \n"[i == 4];
    }

    return 0;
}