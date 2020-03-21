#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

int n;
char str[maxn], ans[maxn];
stack<char> stk;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    scanf("%s", str + 1);
    stk.push(str[1]);
    up(i, 2, n) {
        if (stk.size() & 1) {
            if (stk.top() == str[i]) continue;
            stk.push(str[i]);
        } else
            stk.push(str[i]);
    }
    if (stk.size() & 1) stk.pop();
    printf("%d\n", n - stk.size());
    int sz = stk.size();
    dn(i, sz, 1) {
        ans[i] = stk.top();
        stk.pop();
    }
    up(i, 1, sz) printf("%c", ans[i]);
    printf("\n");

    return 0;
}