#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/A/Input/test6.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int T = 100;
    cout << T << '\n';
    while (T--) {
        int n = 1;
        cout << n << '\n';
        while (n--) {
            cout << rint(1, 100) << ' ';
        }
        cout << '\n';
    }

    return 0;
}