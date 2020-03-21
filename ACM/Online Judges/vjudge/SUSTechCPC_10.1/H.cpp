#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int V, N;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> N;
    double tot = V * N;
    for (int i = 1; i <= 9; ++i) cout << (int)ceil(tot / 10 * i) << ' ';
    cout << '\n';

    return 0;
}