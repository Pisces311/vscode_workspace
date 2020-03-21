#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 4e1 + 5;
const int inf = 0x3f3f3f3f;

char a;
int n;
char m[maxn][maxn << 1];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int case_num = 1;
    while (scanf("%s", &a) && a != '@') {
        if (case_num != 1) printf("\n");
        scanf("%d", &n);
        up(i, 1, n) up(j, 1, 2 * n - 1) m[i][j] = ' ';
        up(i, 1, 2 * n - 1) m[n][i] = a;
        up(i, 1, n) m[n - i + 1][i] = a;
        up(i, 1, n - 1) m[1 + i][n + i] = a;
        up(i, 1, n) {
            up(j, 1, n + i - 1) printf("%c", m[i][j]);
            printf("\n");
        }
        ++case_num;
    }

    return 0;
}