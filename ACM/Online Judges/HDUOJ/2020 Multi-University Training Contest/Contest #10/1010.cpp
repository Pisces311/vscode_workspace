#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 10;

int a[maxn];
int row[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
int col[] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3};

bool check(int i, int j) {
    int k;
    for (k = 1; k <= 9; ++k) {
        if (row[k] != row[i] && row[k] != row[j] && col[k] != col[i] &&
            col[k] != col[j])
            break;
    }
    int XOR = 0;
    for (int l = 1; l <= 9; ++l)
        if (l != i && l != j && l != k) XOR ^= a[l] - 1;
    return XOR ^ a[k];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 9; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= 9; ++i) {
            bool win = true;
            for (int j = 1; j <= 9; ++j) {
                if (row[j] != row[i] && col[j] != col[i]) win &= check(i, j);
            }
            ans += win;
        }
        cout << ans << '\n';
    }

    return 0;
}