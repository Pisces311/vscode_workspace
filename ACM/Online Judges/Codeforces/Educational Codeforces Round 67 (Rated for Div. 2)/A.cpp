#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, s, t;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> s >> t;
        if (s == n && t == n)
            cout << 1 << endl;
        else if (s == n)
            cout << n - t + 1 << endl;
        else if (t == n)
            cout << n - s + 1 << endl;
        else
            cout << max(s, t) - (s + t - n) + 1 << endl;
    }

    return 0;
}