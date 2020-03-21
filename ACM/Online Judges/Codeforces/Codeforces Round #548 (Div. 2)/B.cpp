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

int n;
ll ans = 0;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n;
    up(i, 1, n) cin >> a[i];
    int val = INT_MAX;
    dn(i, n, 1) {
        ans += min(val, a[i]);
        val = min(val, a[i]);
        --val;
        if (val < 0) val = 0;
    }
    cout << ans << endl;
    return 0;
}