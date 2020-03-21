#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

ll H, n, ans;
ll d[maxn];
ll pre[maxn];

bool judge(ll num) {
    long double base = (long double)num * (-1 * pre[n]);
    if (base >= H) {
        ans = num * n;
        return true;
    }
    up(i, 1, n) if (base - pre[i] >= H) {
        ans = num * n + i;
        return true;
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    cin >> H >> n;
    up(i, 1, n) {
        cin >> d[i];
        pre[i] = pre[i - 1] + d[i];
    }
    up(i, 1, n) {
        if (-1 * pre[i] >= H) {
            cout << i << endl;
            return 0;
        }
    }
    if (pre[n] >= 0) {
        cout << -1 << endl;
        return 0;
    }
    ll l = 1, r = 2e12 + 5;
    ll mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;

    return 0;
}