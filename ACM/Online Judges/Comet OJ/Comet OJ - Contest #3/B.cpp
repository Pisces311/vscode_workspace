#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;

int N, ans = 0, flag = 1, s = 0, e = 0;
int a[3][maxn];
bool change = true;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    up(i, 1, 2) up(j, 1, N) scanf("%d", &a[i][j]);
    up(i, 1, N) if (a[1][i] || a[2][i]) e = i;
    dn(i, N, 1) if (a[1][i] || a[2][i]) s = i;
    up(i, s, e) {
        if (!a[1][i] && !a[2][i])
            ++ans;
        else if (a[1][i] && flag == 1 && !a[2][i])
            change = false;
        else if (a[2][i] && flag == 2 && !a[1][i])
            change = false;
        else if (a[2][i] && flag == 1 && !a[1][i] && change) {
            change = false;
            flag = 2;
        } else if (a[2][i] && flag == 1 && !a[1][i] && !change) {
            ++ans;
            change = true;
        } else if (a[1][i] && flag == 2 && !a[2][i] && change) {
            change = false;
            flag = 1;
        } else if (a[1][i] && flag == 2 && !a[2][i] && !change) {
            ++ans;
            change = true;
        } else if (a[1][i] && a[2][i])
            change = true;
    }
    printf("%d\n", ans);

    return 0;
}