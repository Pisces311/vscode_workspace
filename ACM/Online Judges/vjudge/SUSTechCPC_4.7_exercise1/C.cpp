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

const int maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
ll x[maxn * maxn], y[maxn * maxn], ma[maxn][maxn], bo[maxn];

ll Cx(int i) {
    return (12345 + x[i - 1] * 23456 + x[i - 2] * 34567 +
            x[i - 1] * x[i - 2] * 45678) %
           5837501;
}

ll Cy(int i) {
    return (56789 + y[i - 1] * 67890 + y[i - 2] * 78901 +
            y[i - 1] * y[i - 2] * 89012) %
           9860381;
}

ll Cz(int i) { return (x[i] * 90123 + y[i]) % 8475871 + 1; }

void dijkstra() {
    up(i, 0, n - 1) {
        x[i] = ma[0][i];
    }
    mem(bo, 0);
    bo[0] = 1;
    up(i, 0, n - 2) {
        int u = 0;
        ll mi = inf;
        up(j, 0, n - 1) {
            if (!bo[j] && mi > x[j]) {
                mi = x[j];
                u = j;
            }
        }
        bo[u] = 1;
        up(j, 0, n - 1) {
            if (!bo[j] && x[j] > ma[u][j] + mi) {
                x[j] = ma[u][j] + mi;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    int t;
    while (~scanf("%d %d %lld %lld %lld %lld", &n, &m, &x[0], &x[1], &y[0],
                  &y[1])) {
        t = n * n;
        ma[0][0] = inf, ma[0][1] = Cz(1);
        up(i, 2, t - 1) {
            x[i] = Cx(i), y[i] = Cy(i);
            if (i / n != i % n)
                ma[i / n][i % n] = Cz(i);
            else
                ma[i / n][i % n] = inf;
        }
        dijkstra();
        ll mi = m;
        up(i, 0, n - 1) if (x[i] != inf) mi = min((ll)mi, x[i] % m);
        printf("%I64d\n", mi);
    }

    return 0;
}