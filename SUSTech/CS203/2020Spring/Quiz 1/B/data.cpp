#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/B/Input/test4.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int T = 10000;
    cout << T << '\n';
    while (T--) {
        int f = rint(0, 1e8), w = rint(0, 1e8), s = rint(0, 1e8);
        cout << f << ' ' << w << ' ' << s << '\n';
    }

    return 0;
}