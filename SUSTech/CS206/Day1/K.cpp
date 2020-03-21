#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 8e1 + 5;
const int inf = 0x3f3f3f3f;

int n;
char m[maxn][maxn];
char a, b;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int case_num = 1;
    while (~scanf("%d %c %c", &n, &a, &b)) {
        if (case_num != 1) printf("\n");
        int num = 1;
        while (num <= n / 2 + 1) {
            if ((n / 2 + 1) & 1)
                up(i, num, n - num + 1) up(j, num, n - num + 1) m[i][j] =
                    num & 1 ? a : b;
            else
                up(i, num, n - num + 1) up(j, num, n - num + 1) m[i][j] =
                    num & 1 ? b : a;
            ++num;
        }
        if (n != 1) m[1][1] = m[1][n] = m[n][1] = m[n][n] = ' ';
        up(i, 1, n) {
            up(j, 1, n) printf("%c", m[i][j]);
            printf("\n");
        }
        ++case_num;
    }

    return 0;
}