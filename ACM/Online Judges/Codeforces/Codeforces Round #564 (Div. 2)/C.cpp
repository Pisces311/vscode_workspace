#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
int a[maxn], pile[maxn], hand[maxn];
int t, cnt = 0, x, y = 0, z;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    up(i, 1, n) {
        cin >> t;
        ++a[t];
        ++hand[t];
    }
    up(i, 1, n) cin >> pile[i];
    bool ok;
    int next;
    if (a[1] == 0) {
        up(i, 1, n) if (pile[i] == 1) {
            next = 1;
            ok = true;
            while (ok) {
                if (i == n)
                    break;
                else if (pile[++i] != ++next)
                    ok = false;
            }
            if (!ok) break;
        }
    }
    next = 0;
    if (ok) {
        x = pile[n] + 1;
        if (x - 1 == n) next = 1;
        up(i, 1, n) {
            if (hand[x] == 1)
                ++cnt;
            else
                break;
            ++hand[pile[i]];
            if (x >= n) next = 1;
            ++x;
        }
    }
    if (next) {
        cout << cnt << endl;
        return 0;
    }
    cnt = 0;
    int p = 1;
    for (int i = 1;; ++i) {
        if (a[p] == 1) p++;
        a[pile[i]]++;
        cnt++;
        if (p == n + 1) break;
    }
    cout << cnt << endl;

    return 0;
}