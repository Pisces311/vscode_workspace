#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e3 + 5;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int n, ans;
char str[maxn][8];
int w[maxn][maxn];
bool vis[maxn];
int lowc[maxn];

inline void init() {
    ans = 0;
    mem(vis, false);
}

int dis(int x, int y) {
    int a = 0;
    up(i, 0, 6) if (str[x][i] != str[y][i])++ a;
    return a;
}

void prim() {
    vis[0] = true;
    up(i, 1, n - 1) lowc[i] = w[0][i];
    up(i, 1, n - 1) {
        int minc = INT_MAX;
        int p = -1;
        up(j, 0, n - 1) {
            if (!vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        }
        ans += minc;
        vis[p] = true;
        up(j, 0, n - 1) if (!vis[j] && lowc[j] > w[p][j]) lowc[j] = w[p][j];
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while ((scanf("%d", &n) != EOF) && n) {
        init();
        up(i, 0, n - 1) scanf("%s", str[i]);
        up(i, 0, n - 1) up(j, i + 1, n - 1) w[j][i] = w[i][j] = dis(i, j);
        prim();
        printf("The highest possible quality is 1/%d.\n", ans);
    }

    return 0;
}