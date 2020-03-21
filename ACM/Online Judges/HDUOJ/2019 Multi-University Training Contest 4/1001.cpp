#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int T, N;
int a[maxn];

int find(int x) {
    int pos = 1;
    while (x) {
        if (x & 1) {
            x >>= 1;
            ++pos;
        } else
            break;
    }
    return pos;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        scanf("%d", &N);
        for (int i = 2; i <= N; ++i) {
            int res = find(i);
            if (1 << (res - 1) <= N) {
                a[i] = 1 << (res - 1);
            } else {
                ++ans;
                a[i] = 1;
            }
        }
        printf("%d\n", ans);
        for (int i = 2; i <= N; ++i) {
            printf("%d%c", a[i], i == N ? '\n' : ' ');
        }
    }

    return 0;
}