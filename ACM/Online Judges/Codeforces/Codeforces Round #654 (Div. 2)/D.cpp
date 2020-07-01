#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

int t, n, k;
int mat[maxn][maxn];

void fill_mat() {
    if (!k) return;
    for (int i = 1; i <= n; ++i) {
        int x = 1, y = i;
        for (int j = 1; j <= n; ++j) {
            mat[x][y] = 1;
            ++x, ++y;
            if (x > n) x = 1;
            if (y > n) y = 1;
            --k;
            if (!k) return;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k % n)
            cout << "2\n";
        else
            cout << "0\n";
        memset(mat, 0, sizeof(mat));
        fill_mat();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cout << mat[i][j];
            cout << '\n';
        }
    }

    return 0;
}