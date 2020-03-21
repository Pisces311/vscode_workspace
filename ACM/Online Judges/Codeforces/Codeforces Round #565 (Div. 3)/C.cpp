#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e5 + 5;

int n;
int a[] = {0, 4, 8, 15, 16, 23, 42};
int b[maxn], cnt[7];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    cnt[0] = INT_MAX;
    up(i, 1, n) scanf("%d", &b[i]);
    up(i, 1, n) up(j, 1, 6) if (b[i] == a[j] && cnt[j - 1]) {
        cnt[j]++;
        cnt[j - 1]--;
    }
    printf("%d\n", n - 6 * cnt[6]);

    return 0;
}