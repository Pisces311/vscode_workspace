#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4.5e2 + 5;
const int inf = 0x3f3f3f3f;

int v, e;
int g[maxn][maxn], s[maxn];

inline void init() { memset(g, 0, sizeof(g)); }

int k4(int i, int j, int k) {
    int mak4 = 0;
    for (int l = k + 1; l <= v; ++l) {
        if (g[i][l] && g[j][l] && g[k][l]) mak4 = max(mak4, s[l]);
    }
    return mak4;
}

int k3(int i, int j) {
    int mak3 = 0;
    for (int k = j + 1; k <= v; ++k) {
        if (g[i][k] && g[j][k]) mak3 = max(mak3, s[k] + k4(i, j, k));
    }
    return mak3;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &v, &e)) {
        init();
        for (int i = 1; i <= v; ++i) scanf("%d", &s[i]);
        for (int i = 1; i <= e; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u][v] = 1;
            g[v][u] = 1;
        }
        int ma = 0;
        for (int i = 1; i <= v; ++i) {
            for (int j = i + 1; j <= v; ++j) {
                if (g[i][j]) ma = max(ma, s[i] + s[j] + k3(i, j));
            }
        }
        printf("%d\n", ma);
    }

    return 0;
}