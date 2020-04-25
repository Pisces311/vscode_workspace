#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
char s[15];
int mat[5][5], tmp[5][5], p[10];

int cal() {
    int ret = 0;
    ret += (mat[1][1] ^ mat[2][2]) * p[7];
    ret += (mat[1][2] ^ mat[2][2]) * p[6];
    ret += (mat[1][3] ^ mat[2][2]) * p[5];
    ret += (mat[2][3] ^ mat[2][2]) * p[4];
    ret += (mat[3][3] ^ mat[2][2]) * p[3];
    ret += (mat[3][2] ^ mat[2][2]) * p[2];
    ret += (mat[3][1] ^ mat[2][2]) * p[1];
    ret += (mat[2][1] ^ mat[2][2]) * p[0];
    return ret;
}

void transfer() {
    for (int j = 3, x = 1; j >= 1; --j, ++x)
        for (int i = 1, y = 1; i <= 3; ++i, ++y) tmp[i][j] = mat[x][y];
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) mat[i][j] = tmp[i][j];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p[0] = 1;
    for (int i = 1; i <= 10; ++i) p[i] = p[i - 1] * 2;
    cin >> n;
    while (n--) {
        cin >> s;
        int cnt = 0;
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j) mat[i][j] = s[cnt++] - '0';
        int ans = cal();
        transfer();
        ans = min(ans, cal());
        transfer();
        ans = min(ans, cal());
        transfer();
        ans = min(ans, cal());
        cout << ans << '\n';
    }

    return 0;
}