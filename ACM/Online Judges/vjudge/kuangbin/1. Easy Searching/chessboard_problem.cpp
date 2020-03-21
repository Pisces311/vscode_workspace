#include <string.h>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 9;

int n, k, cnt, ans = 0;
char c[maxn][maxn];
bool vis[maxn];

inline void init() {
    ans = cnt = 0;
    memset(vis, false, sizeof(vis));
}

void dfs(int i) {
    if (cnt == k) {
        ++ans;
        return;
    }
    if (i > n) return;
    for (int j = 1; j <= n; ++j) {
        if (!vis[j] && c[i][j] == '#') {
            vis[j] = true;
            ++cnt;
            dfs(i + 1);
            vis[j] = false;
            --cnt;
        }
    }
    dfs(i + 1);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    while (cin >> n >> k) {
        init();
        if (n == -1 && k == -1) break;
        for (int i = 1; i <= n; ++i) cin >> c[i] + 1;
        dfs(1);
        cout << ans << endl;
    }

    return 0;
}