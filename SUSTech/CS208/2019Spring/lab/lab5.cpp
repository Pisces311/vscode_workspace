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

int T, man, big, small, ans;

inline void init() { ans = 0; }

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        init();
        cin >> man >> big >> small;
        if (big & 1 && man) {
            --man;
            --big;
            ++ans;
        }
        int tmp = min(man, (int)ceil(small / 2.0));
        ans += tmp;
        man -= tmp;
        small = max(0, small - 2 * tmp);
        ans += ceil(small / 3.0);
        ans += man;
        if (man < big) ans += ceil((big - man) / 2.0);
        cout << ans << endl;
    }

    return 0;
}