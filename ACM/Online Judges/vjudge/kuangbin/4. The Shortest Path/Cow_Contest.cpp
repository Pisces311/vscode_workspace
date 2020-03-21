#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int N, M;
int g[maxn][maxn];

void floyd() {
    up(k, 1, N) up(i, 1, N) up(j, 1, N) if (g[i][k] == 1 && g[k][j] == 1)
        g[i][j] = 1;
    else if (g[i][k] == -1 && g[k][j] == -1) g[i][j] = -1;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &N, &M);
    int u, v;
    up(i, 1, M) {
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = -1;
    }
    floyd();
    int cnt = 0;
    up(i, 1, N) {
        int not_0 = 0;
        up(j, 1, N) if (g[i][j] != 0)++ not_0;
        if (not_0 == N - 1) ++cnt;
    }
    print(cnt);

    return 0;
}