#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
int g[maxn][maxn];
int block[maxn][maxn];

void pre() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (g[i][j]) block[i][j] = block[i - 1][j] + g[i][j];
        }
}

int cal(int i, int j) {
    int cnt = 0, ma = 0, mi = block[i][j];
    for (int r = j; r <= m; ++r) {
        if (mi <= block[i][r])
            ++cnt;
        else {
            ma = max(ma, cnt * mi);
            mi = block[i][r];
            ++cnt;
        }
    }
    ma = max(ma, cnt * mi);
    return ma;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; ++i) {
        char ch;
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &ch);
            g[i][j] = (ch == '1');
        }
        getchar();
    }
    pre();
    int max1 = 0, max2 = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j]) {
                int res = cal(i, j);
                if (res > max1) {
                    max2 = max1;
                    max1 = res;
                } else if (res > max2)
                    max2 = res;
            }
    printf("%d\n", max2);

    return 0;
}