#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e1 + 5;

int t;
char ans;
char g[maxn][maxn];

void check_row(int i) {
    if (g[i][1] == g[i][2] && g[i][2] == g[i][3] && g[i][3] != '.')
        ans = g[i][1];
}

void check_col(int j) {
    if (g[1][j] == g[2][j] && g[2][j] == g[3][j] && g[3][j] != '.')
        ans = g[1][j];
}

void check_cross1() {
    if (g[1][1] == g[2][2] && g[2][2] == g[3][3] && g[3][3] != '.')
        ans = g[2][2];
}

void check_cross2() {
    if (g[1][3] == g[2][2] && g[2][2] == g[3][1] && g[3][1] != '.')
        ans = g[2][2];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        for (int i = 1; i <= 3; ++i) cin >> (g[i] + 1);
        ans = '.';
        for (int i = 1; i <= 3; ++i) check_row(i);
        for (int j = 1; j <= 3; ++j) check_col(j);
        check_cross1();
        check_cross2();
        if (ans == '.')
            cout << "ongoing\n";
        else
            cout << ans << '\n';
    }

    return 0;
}