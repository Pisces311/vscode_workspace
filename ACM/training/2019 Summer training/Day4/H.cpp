#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int val, in;
    bool operator<(const node& a) const { return val < a.val; }
} b[maxn];

int n, ans = 0;

inline bool check(int x) {
    int dif = b[3].val - b[x == 1 ? 2 : 1].val;
    up(i, 4, n) if (b[i].val - b[i - 1].val != dif) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) {
        cin >> b[i].val;
        b[i].in = i;
    }
    sort(b + 1, b + n + 1);
    if (check(1))
        ans = b[1].in;
    else if (check(2))
        ans = b[2].in;
    else {
        int dif = b[2].val - b[1].val;
        up(i, 3, n) {
            if (b[i].val - b[i - 1].val != dif) {
                if (i != n) {
                    if (b[i + 1].val - b[i - 1].val == dif && !ans) {
                        ans = b[i].in;
                        ++i;
                    } else
                        ans = -1;
                } else {
                    if (!ans) {
                        ans = b[i].in;
                        ++i;
                    } else
                        ans = -1;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}