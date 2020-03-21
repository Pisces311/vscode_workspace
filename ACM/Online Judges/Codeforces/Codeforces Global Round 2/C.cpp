#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 5e2 + 5;
const int maxm = 5e2 + 5;

int n, m;
int a[maxn][maxm], b[maxn][maxm];
bool ok = true;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);
    up(i, 1, n) up(j, 1, m) scan(a[i][j]);
    up(i, 1, n) up(j, 1, m) scan(b[i][j]);
    up(i, 1, n) {
        int error = 0;
        up(j, 1, m) if (a[i][j] != b[i][j])
            ++error;
        if (error % 2 != 0) ok = false;
    }
    up(i, 1, m) {
        int error = 0;
        up(j, 1, n) if (a[j][i] != b[j][i])
            ++error;
        if (error % 2 != 0) ok = false;
    }
    if (ok)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}