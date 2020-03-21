#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int N, v, a = 0, b = 0, order = 0, scc = 0;
int dfn[maxn], low[maxn], in[maxn], belong[maxn], num[maxn];
int indeg[maxn], outdeg[maxn];
vector<int> g[maxn];
stack<int> stk;

void tarjan(int x) {
    low[x] = dfn[x] = ++order;
    stk.push(x);
    in[x] = true;
    up(i, 0, (int)g[x].size() - 1) {
        int v = g[x][i];
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (in[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x]) {
        ++scc;
        int t;
        do {
            t = stk.top();
            stk.pop();
            in[t] = false;
            belong[t] = scc;
            num[scc]++;
        } while (t != x);
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    up(i, 1, N) while (cin >> v && v) g[i].push_back(v);
    up(i, 1, N) if (!dfn[i]) tarjan(i);
    up(i, 1, N) {
        up(j, 0, (int)g[i].size() - 1) {
            int v = g[i][j];
            if (belong[i] != belong[v]) {
                ++outdeg[belong[i]];
                ++indeg[belong[v]];
            }
        }
    }
    up(i, 1, scc) {
        if (indeg[i] == 0) ++a;
        if (outdeg[i] == 0) ++b;
    }
    cout << a << endl << (scc == 1 ? 0 : max(a, b)) << endl;

    return 0;
}