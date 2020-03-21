#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

int T, N;
int h[maxn], lm[maxn], rm[maxn];
stack<int> stk;
vector<int> tmp;

void solve(int a[]) {
    up(i, 2, N) {
        while (!stk.empty() && h[i] > h[stk.top()]) {
            tmp.push_back(stk.top());
            stk.pop();
        }
        if (!tmp.empty()) {
            a[tmp[0]] = 0;
            up(j, 1, (int)tmp.size() - 1) a[tmp[j]] = tmp[j - 1];
            tmp.clear();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        tmp.push_back(stk.top());
        stk.pop();
    }
    if (!tmp.empty()) {
        a[tmp[0]] = 0;
        up(j, 1, (int)tmp.size() - 1) a[tmp[j]] = tmp[j - 1];
        tmp.clear();
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_no, 1, T) {
        printf("Case %d:\n", case_no);
        scanf("%d", &N);
        up(i, 1, N) scanf("%d", &h[i]);
        stk.push(1);
        solve(rm);
        reverse(h + 1, h + N + 1);
        stk.push(1);
        solve(lm);
        reverse(lm + 1, lm + N + 1);
        up(i, 1, N) if (lm[i]) lm[i] = N - lm[i] + 1;
        up(i, 1, N) printf("%d %d\n", lm[i], rm[i]);
    }

    return 0;
}