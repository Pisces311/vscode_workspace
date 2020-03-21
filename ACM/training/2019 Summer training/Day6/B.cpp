#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e1 + 5;
const int inf = 0x3f3f3f3f;

int a[maxn][maxn], cnt[maxn], s, X1, Y1, ans;
map<int, int> vis;

int state() {
    int key = 0;
    up(i, 0, 3) up(j, 0, 3) key = key << 2 | a[j][i];
    return key;
}

bool win(int p) {
    up(x, 0, 3) up(y, 0, 3) {
        if (x + 2 <= 3 && a[x][y] == p && a[x + 1][y] == p && a[x + 2][y] == p)
            return true;
        if (y + 2 <= 3 && a[x][y] == p && a[x][y + 1] == p && a[x][y + 2] == p)
            return true;
        if (x + 2 <= 3 && y + 2 <= 3 && a[x][y] == p && a[x + 1][y + 1] == p &&
            a[x + 2][y + 2] == p)
            return true;
        if (x - 2 >= 0 && y + 2 <= 3 && a[x][y] == p && a[x - 1][y + 1] == p &&
            a[x - 2][y + 2] == p)
            return true;
    }
    return false;
}

void dfs(int p) {
    int k = state();
    if (vis.find(k) != vis.end()) return;
    ++vis[k];
    if (win(1) || win(2) || a[X1][Y1]) {
        if (win(2) && a[X1][Y1] == 2) ++ans;
        return;
    }
    up(x, 0, 3) {
        if (cnt[x] == 4) continue;
        a[x][cnt[x]++] = p;
        dfs(p ^ 3);
        a[x][--cnt[x]] = 0;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &s);
    scanf("%d %d", &Y1, &X1);
    s--, Y1--, X1--;
    a[s][cnt[s]++] = 1;
    dfs(2);
    printf("%d\n", ans);

    return 0;
}