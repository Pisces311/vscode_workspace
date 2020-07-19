#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
int limit[] = {0, 60, 62, 65, 67, 70, 75, 80, 85, 90, 95};

double get(int x) {
    if (x < 60)
        return 0;
    else if (x <= 61)
        return 1;
    else if (x <= 64)
        return 1.7;
    else if (x <= 66)
        return 2;
    else if (x <= 69)
        return 2.3;
    else if (x <= 74)
        return 2.7;
    else if (x <= 79)
        return 3;
    else if (x <= 84)
        return 3.3;
    else if (x <= 89)
        return 3.7;
    else if (x <= 94)
        return 4;
    else
        return 4.3;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        double ans = 0;
        for (int i = 0; i < 11; ++i) {
            int x = limit[i];
            if (x > n) break;
            for (int j = 0; j < 11; ++j) {
                int y = limit[j];
                if (x + y > n) break;
                for (int k = 0; k < 11; ++k) {
                    int z = limit[k];
                    if (x + y + z > n) break;
                    ans =
                        max(ans, get(x) + get(y) + get(z) + get(n - x - y - z));
                }
            }
        }
        printf("%.1f\n", ans);
    }

    return 0;
}