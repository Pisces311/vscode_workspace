#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e2 + 5;

int N, K, top = 0;
int a[maxn];
ll ans[maxn * maxn], sum = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &K);
    up(i, 1, N) scanf("%d", &a[i]);
    up(i, 1, N) up(j, i + 1, N) ans[++top] = a[i] + a[j];
    sort(ans + 1, ans + top + 1);
    up(i, 1, K) sum += ans[top - i + 1];
    printf("%lld", sum);

    return 0;
}