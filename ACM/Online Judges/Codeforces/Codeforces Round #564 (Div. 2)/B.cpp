#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    m = n / 2 + 1;
    cout << m << endl;
    bool r = true;
    int x = 1, y = 1;
    while (n--) {
        cout << x << ' ' << y << endl;
        if (r) {
            x += 1;
            r = !r;
        } else {
            y += 1;
            r = !r;
        }
    }

    return 0;
}