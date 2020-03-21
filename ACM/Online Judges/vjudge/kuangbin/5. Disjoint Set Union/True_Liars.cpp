#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define mem(a, member) memset(a, member, sizeof(a))
#define up(i, a, member) for (int i = a; i <= member; ++i)
#define dn(i, a, member) for (int i = a; i >= member; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 6e2 + 5;
const int inf = 0x3f3f3f3f;

int n, p1, p2, u, v;
char resp[5];
int fa[maxn], val[maxn], a[maxn][2];
vector<int> member[maxn][2], ans;
bool vis[maxn];
int dp[maxn][maxn / 2], pre[maxn][maxn / 2];

inline void init() {
    mem(fa, -1);
    mem(val, 0);
    mem(vis, false);
    mem(dp, 0);
    mem(a, 0);
    up(i, 1, p1 + p2) {
        member[i][0].clear();
        member[i][1].clear();
    }
    ans.clear();
}

int find(int x) {
    if (fa[x] == -1) return x;
    int tmp = find(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 2;
    return fa[x] = tmp;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &n, &p1, &p2)) {
        if (n + p1 + p2 == 0) break;
        init();
        while (n--) {
            scanf("%d %d %s", &u, &v, resp + 1);
            int x = find(u), y = find(v);
            if (x != y) {
                fa[x] = y;
                val[x] = (val[v] - val[u] + (resp[1] == 'n') + 2) % 2;
            }
        }
        int cnt = 1;
        up(i, 1, p1 + p2) if (!vis[i]) {
            int tmp = find(i);
            up(j, 1, p1 + p2) {
                if (find(j) == tmp) {
                    vis[j] = true;
                    member[cnt][val[j]].push_back(j);
                    ++a[cnt][val[j]];
                }
            }
            ++cnt;
        }
        dp[0][0] = 1;
        up(i, 1, cnt - 1) {
            dn(j, p1, 0) {
                if (j - a[i][0] >= 0 && dp[i - 1][j - a[i][0]]) {
                    dp[i][j] += dp[i - 1][j - a[i][0]];
                    pre[i][j] = j - a[i][0];
                }
                if (j - a[i][1] >= 0 && dp[i - 1][j - a[i][1]]) {
                    dp[i][j] += dp[i - 1][j - a[i][1]];
                    pre[i][j] = j - a[i][1];
                }
            }
        }
        if (dp[cnt - 1][p1] != 1)
            printf("no\n");
        else {
            int t = p1;
            dn(i, cnt - 1, 1) {
                int tmp = t - pre[i][t];
                if (tmp == a[i][0])
                    up(j, 0, a[i][0] - 1) ans.push_back(member[i][0][j]);
                else
                    up(j, 0, a[i][1] - 1) ans.push_back(member[i][1][j]);
                t = pre[i][t];
            }
            sort(ans.begin(), ans.end());
            up(i, 0, (int)ans.size() - 1) printf("%d\n", ans[i]);
            printf("end\n");
        }
    }
    return 0;
}