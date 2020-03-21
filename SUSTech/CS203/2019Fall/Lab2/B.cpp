#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int T, N;
int x[maxn], p[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> N;
    for (int i = 1; i <= T; ++i) cin >> x[i];
    for (int i = 1; i <= N; ++i) cin >> p[i];
    for (int i = 1; i <= T; ++i) {
        int pos = lower_bound(p + 1, p + N + 1, x[i]) - p;
        if (p[pos] == x[i])
            cout << "Meow\n";
        else
            cout << x[i] - p[pos - 1] << '\n';
    }

    return 0;
}