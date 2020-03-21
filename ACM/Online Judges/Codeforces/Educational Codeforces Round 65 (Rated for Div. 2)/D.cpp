#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

struct brak {
    int in;
    char type;
};

int n;
char rbs[maxn];
int state[maxn];
stack<brak> stk;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    scanf("%s", rbs + 1);
    up(i, 1, n) {
        if (rbs[i] == '(' && stk.size() & 1) {
            stk.push({i, rbs[i]});
            state[i] = 1;
        } else if (rbs[i] == '(') {
            stk.push({i, rbs[i]});
            state[i] = 0;
        } else {
            state[i] = state[stk.top().in];
            stk.pop();
        }
    }
    up(i, 1, n) printf("%d", state[i]);
    printf("\n");

    return 0;
}