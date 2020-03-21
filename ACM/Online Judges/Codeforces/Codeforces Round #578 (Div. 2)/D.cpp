#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int n, k;
char a[maxn][maxn];
int dy[maxn][maxn];
int y[maxn][maxn];
int cur = 0;

void update(int x1, int x2, int y1, int y2) {
    dy[x1][y1]++;
    dy[x2][y2]++;
    dy[x1][y2]--;
    dy[x2][y1]--;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
    for (int i = 1; i <= n; ++i) {
        int mi = 0, ma = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 'B') {
                ma = j;
                if (!mi) mi = j;
            }
        }
        if (!mi)
            ++cur;
        else if (ma - mi + 1 <= k)
            update(max(0, i - k), i, max(0, ma - k), mi);
    }
    for (int j = 1; j <= n; ++j) {
        int mi = 0, ma = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][j] == 'B') {
                ma = i;
                if (!mi) mi = i;
            }
        }
        if (!mi)
            ++cur;
        else if (ma - mi + 1 <= k)
            update(max(0, ma - k), mi, max(0, j - k), j);
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            y[i][j] = -y[i + 1][j + 1] + y[i][j + 1] + y[i + 1][j] + dy[i][j];
            ans = max(ans, cur + y[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}