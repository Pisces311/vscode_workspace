#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 3e1 + 5;

int r, c;
int a[maxn][maxn];

int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }

void chang_line(int q, int w, int e) { up(i, 1, c) swap(a[q][i], a[w][i]); }

int Rank(int n, int m) {
    int s = 0;
    for (int i = 1, j = 1; i <= n && j <= m; i++, j++) {
        int chk = 0;
        up(v, i, n) {
            if (a[v][j] != 0) {
                chk = v;
                break;
            }
        }
        if (chk == 0)
            i--;
        else {
            chang_line(chk, i, j);
            up(w, i + 1, n) {
                if (a[w][j] != 0) {
                    int g = gcd(a[w][j], a[i][j]);
                    int pa = a[i][j] / g, pb = a[w][j] / g;
                    up(z, j, m) a[w][z] = a[w][z] * pa - a[i][z] * pb;
                }
            }
            s++;
        }
    }
    return s;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &r, &c);
    up(i, 1, r) up(j, 1, c) scanf("%d", &a[i][j]);
    int rank = Rank(r, c);
    int ans = max(1, rank);
    printf("%d\n", min(r * c, ans * (r + c)));

    return 0;
}