#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;

int n, ans = 0;
int cnt[30], A[30], B[30];
string a[maxn];

int add(int x) {
    if (x <= 0) return 0;
    return x + add(x - 1);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(i, 1, n)++ cnt[a[i][0] - 'a' + 1];
    up(i, 1, 26) {
        A[i] = cnt[i] / 2;
        B[i] = cnt[i] - A[i];
    }
    up(i, 1, 26) {
        ans += add(A[i] - 1);
        ans += add(B[i] - 1);
    }
    cout << ans << endl;

    return 0;
}