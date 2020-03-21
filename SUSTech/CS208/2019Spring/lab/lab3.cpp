#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 5e3 + 5;
const int max_val = 1e4 + 5;

struct interval {
    int l, r;
    friend bool operator<(const interval& a, const interval& b) {
        if (a.r == b.r)
            return a.l < b.l;
        else
            return a.r < b.r;
    }
} a[maxn];

int N, cnt;
bool vis[max_val];

bool judge(int n) {
    memset(vis, false, sizeof(vis));
    up(i, 1, N) {
        cnt = n;
        up(j, a[i].l, a[i].r) {
            if (!vis[j]) {
                vis[j] = true;
                --cnt;
            }
            if (!cnt) break;
        }
        if (cnt) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("D:/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    up(i, 1, N) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + N + 1);
    int l = 0, r = a[1].r - a[1].l + 1;
    int mid = (l + r) / 2;
    while (l <= r) {
        if (judge(mid))
            l = mid + 1;
        else
            r = mid - 1;
        mid = (l + r) / 2;
    }
    cout << mid << endl;

    return 0;
}