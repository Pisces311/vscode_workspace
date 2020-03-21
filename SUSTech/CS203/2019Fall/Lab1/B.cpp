#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int g[10][10];
char s[5];
bool vis[10];

bool check_row(int x, int y) {
    int cntr = 0, totr = 45;
    for (int j = 1; j <= 9; ++j)
        if (g[x][j]) {
            ++cntr;
            totr -= g[x][j];
        }
    if (cntr == 8) {
        g[x][y] = totr;
        return true;
    } else
        return false;
}

bool check_col(int x, int y) {
    int cntc = 0, totc = 45;
    for (int i = 1; i <= 9; ++i)
        if (g[i][y]) {
            ++cntc;
            totc -= g[i][y];
        }
    if (cntc == 8) {
        g[x][y] = totc;
        return true;
    } else
        return false;
}

bool check_block(int x, int y) {
    int cntb = 0, totb = 45;
    for (int i = (x - 1) / 3 * 3 + 1; i < (x - 1) / 3 * 3 + 4; ++i)
        for (int j = (y - 1) / 3 * 3 + 1; j < (y - 1) / 3 * 3 + 4; ++j)
            if (g[i][j]) {
                ++cntb;
                totb -= g[i][j];
            }
    if (cntb == 8) {
        g[x][y] = totb;
        return true;
    } else
        return false;
}

bool check(int x, int y) {
    if (check_row(x, y)) return true;
    if (check_col(x, y)) return true;
    if (check_block(x, y)) return true;
    return false;
}

bool find_special() {
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            if (g[i][j] == 0)
                if (check(i, j)) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cntx = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> s;
            if (s[0] == '|')
                --j;
            else if (s[0] == 'x') {
                g[i][j] = 0;
                ++cntx;
            } else
                g[i][j] = s[0] - '0';
        }
    }
    bool ok = true;
    while (cntx) {
        if (find_special())
            --cntx;
        else {
            ok = false;
            break;
        }
    }
    if (ok)
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; ++j) {
                cout << g[i][j] << ' ';
                if (j % 3 == 0) cout << "| ";
            }
            cout << '\n';
            if (i % 3 == 0 && i != 9) cout << '\n';
        }
    else
        cout << "The test data is incorrect!\n";

    return 0;
}