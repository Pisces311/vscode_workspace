#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int stay[] = {1, 2, 3, 5, 8, 13};

bool check(int x) {
    for (int i = 0; i < 6; ++i)
        if (stay[i] == x) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (check(i)) ++cnt;
        }
        cout << "Case #" << cas << ": " << n - cnt << '\n';
    }

    return 0;
}