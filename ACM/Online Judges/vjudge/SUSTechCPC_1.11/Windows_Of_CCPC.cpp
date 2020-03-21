#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1.2e3 + 5;

int T, k;
char ret[maxn][maxn];

char dfs(int i, int j, int len, bool rev) {
    if (len == 2) {
        if (!rev) {
            if (i == 1 && j == 0)
                return 'P';
            else
                return 'C';
        } else {
            if (i == 1 && j == 0)
                return 'C';
            else
                return 'P';
        }
    } else {
        if (i < len / 2 && j < len / 2)
            return dfs(i, j, len / 2, rev);
        else if (i < len / 2 && j >= len / 2)
            return dfs(i, j - len / 2, len / 2, rev);
        else if (i >= len / 2 && j < len / 2)
            return dfs(i - len / 2, j, len / 2, !rev);
        else if (i >= len / 2 && j >= len / 2)
            return dfs(i - len / 2, j - len / 2, len / 2, rev);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> k;
        int len = 1 << k;
        if (k == 1) {
            cout << "CC\nPC\n";
            continue;
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i < len / 2 && j < len / 2)
                    ret[i][j] = dfs(i, j, len / 2, false);
                else if (i < len / 2 && j >= len / 2)
                    ret[i][j] = dfs(i, j - len / 2, len / 2, false);
                else if (i >= len / 2 && j < len / 2)
                    ret[i][j] = dfs(i - len / 2, j, len / 2, true);
                else if (i >= len / 2 && j >= len / 2)
                    ret[i][j] = dfs(i - len / 2, j - len / 2, len / 2, false);
            }
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) cout << ret[i][j];
            cout << '\n';
        }
    }

    return 0;
}