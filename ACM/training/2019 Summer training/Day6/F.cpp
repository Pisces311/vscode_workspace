#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;

pii dfs(int n, int m) {
    pii tmp = {0, 0};
    if (n == 2) {
        if (m == 0)
            tmp = {1, 1};
        else if (m == 1)
            tmp = {1, 2};
        else if (m == 2)
            tmp = {2, 2};
        else if (m == 3)
            tmp = {2, 1};
        return tmp;
    }
    int t = m / (n * n / 4), s = m % (n * n / 4);
    tmp = dfs(n / 2, s);
    if (t == 0)
        swap(tmp.first, tmp.second);
    else if (t == 1)
        tmp.second += n / 2;
    else if (t == 2) {
        tmp.first += n / 2;
        tmp.second += n / 2;
    } else if (t == 3) {
        int x = n + 1 - tmp.second, y = n / 2 + 1 - tmp.first;
        tmp = {x, y};
    }
    return tmp;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    pii ans = dfs(n, m - 1);
    printf("%d %d\n", ans.first, ans.second);

    return 0;
}