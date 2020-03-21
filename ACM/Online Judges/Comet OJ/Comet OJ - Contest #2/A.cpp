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

ll x;
ll times[1000000], pre[1000000];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> x;
    times[1] = times[2] = 1;
    up(i, 1, 1000000 - 1) {
        if (i > 2) times[i] = pre[i - 1] / 2;
        pre[i] = pre[i - 1] + times[i];
        if (pre[i] > x) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}