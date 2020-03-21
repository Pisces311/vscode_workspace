#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int T, n;
int len[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &len[i]);
        sort(len + 1, len + n + 1);
        int he = min(len[n], len[n - 1]);
        int ans = min(he - 1, n - 2);
        printf("%d\n", max(ans, 0));
    }

    return 0;
}