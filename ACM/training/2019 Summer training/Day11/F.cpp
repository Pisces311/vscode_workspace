#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int judge(int x, int y) {
    if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
        return 31;
    if (x == 4 || x == 6 || x == 9 || x == 11) return 30;
    if (x == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) return 29;
    return 28;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int y, m, d;
    while (~scanf("%d-%d-%d", &y, &m, &d)) {
        int ans = d;
        if (y % 400 != 0 && y % 100 == 0 && m > 2) ans++;
        for (int i = 100; i <= y - 1; i += 100)
            if (i % 400 != 0) ans++;
        ans--;
        while (ans > judge(m, y)) {
            ans -= judge(m, y);
            m++;
            if (m == 13) {
                y++;
                m = 1;
            }
        }
        printf("%d-%02d-%02d\n", y, m, ans);
    }

    return 0;
}