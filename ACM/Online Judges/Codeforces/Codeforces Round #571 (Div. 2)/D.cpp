#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
double a[maxn];
int b[maxn], mark[maxn];
ll sum = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(i, 1, n) {
        b[i] = floor(a[i]);
        if (a[i] == b[i]) mark[i] = 1;
    }
    up(i, 1, n) sum += b[i];
    sum = -sum;
    up(i, 1, n) if (!mark[i] && sum > 0) {
        ++b[i];
        --sum;
    }
    up(i, 1, n) cout << b[i] << endl;

    return 0;
}