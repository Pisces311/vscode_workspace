#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int x, y, z;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> x >> y >> z;
    x -= y;
    if (x > 0) {
        if (z >= x)
            cout << '?' << endl;
        else
            cout << '+' << endl;
    } else if (x == 0) {
        if (z != 0)
            cout << '?' << endl;
        else
            cout << '0' << endl;
    } else {
        if (z >= abs(x))
            cout << '?' << endl;
        else
            cout << '-' << endl;
    }

    return 0;
}