#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

int n;
int a[maxn];
ll dp[maxn];

int main() {
#ifdef DEBUG
    freopen("D:/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> n && n) {
        up(i, 1, n) cin >> a[i];
        up(i, 1, n) {
            dp[i] = a[i];
            up(j, 1, i - 1) if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }

    return 0;
}