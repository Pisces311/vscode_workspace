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

int a, b, c;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;
    int week = min(a / 3, min(b / 2, c / 2));
    a -= week * 3;
    b -= week * 2;
    c -= week * 2;
    int ans = 0;
    up(i, 1, 7) {
        int cur = 0;
        int day = i;
        int tmpa = a, tmpb = b, tmpc = c;
        while (true) {
            if (day == 8) day = 1;
            if (day == 1 || day == 4 || day == 7) {
                if (tmpa == 0) break;
                --tmpa;
            } else if (day == 2 || day == 6) {
                if (tmpb == 0) break;
                --tmpb;
            } else {
                if (tmpc == 0) break;
                --tmpc;
            }
            ++day;
            ++cur;
        }
        ans = max(ans, cur);
    }
    ans += week * 7;
    cout << ans << endl;

    return 0;
}