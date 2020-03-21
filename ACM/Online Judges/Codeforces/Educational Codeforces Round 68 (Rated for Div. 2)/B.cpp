#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

int q, n, m;
char ch;
int row[maxn], col[maxn];
vector<char> g[maxn];

int scan(int x, int y) {
    int cnt = row[x] + col[y];
    if (g[x][y] == '.') --cnt;
    return max(cnt, 0);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d\n", &n, &m);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%c", &ch);
                g[i].push_back(ch);
            }
            getchar();
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j)
                if (g[i][j] == '.') ++cnt;
            row[i] = cnt;
        }
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (g[j][i] == '.') ++cnt;
            col[i] = cnt;
        }
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = min(ans, scan(i, j));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}