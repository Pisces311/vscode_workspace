#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int T, n;
ll ans;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        while (n) {
            int cnt = 0;
            while (pow(2, cnt) <= n) {
                ++cnt;
            }
            ans += pow(2, cnt - 1) - 1;
            n -= pow(2, cnt - 1);
        }
        cout << ans << endl;
    }

    return 0;
}