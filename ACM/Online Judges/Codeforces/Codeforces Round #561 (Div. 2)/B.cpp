#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

int k;
char wa[10010];
char s[6] = "aeiou";

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> k;
    bool ok = 0;
    up(i, 1, k) {
        int x = i, y = k / i;
        if (k % i != 0) continue;
        if (x < 5 || y < 5) continue;
        up(j, 0, k - 1) {
            int t = j / x, p = j % x;
            wa[j] = s[(t + p) % 5];
        }
        ok = 1;
        break;
    }
    if (!ok)
        cout << -1 << endl;
    else
        cout << wa << endl;

    return 0;
}