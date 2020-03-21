#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int a[2 * MAXN];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int x0, y0, x1, y1, x2, y2;
    int maxx, minx;
    memset(a, 0, sizeof(a));
    up(i, 0, n - 1) {
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        y0 += 1e6;
        y1 += 1e6;
        y2 += 1e6;
        maxx = max(max(y0, y1), y2);
        minx = min(min(y0, y1), y2);
        a[minx]++;
        a[maxx + 1]--;
    }
    int ans = 0, cnt = 0;
    up(i, 0, 2*MAXN - 1) {
        cnt += a[i];
        ans = max(ans, cnt);
    }
    print(ans);

    return 0;
}