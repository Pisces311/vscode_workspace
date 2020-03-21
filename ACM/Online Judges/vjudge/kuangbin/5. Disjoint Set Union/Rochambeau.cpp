#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct round {
    int u, v, r;
} r[maxn];

int N, M;
char ch;
int fa[maxn], val[maxn], err[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    int root = find(fa[x]);
    val[x] = (val[x] + val[fa[x]]) % 3;
    return fa[x] = root;
}

void init() {
    up(i, 0, N - 1) {
        fa[i] = i;
        val[i] = 0;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d%d", &N, &M)) {
        up(i, 1, M) {
            scanf("%d%c%d", &r[i].u, &ch, &r[i].v);
            if (ch == '=') r[i].r = 0;
            if (ch == '<') r[i].r = 1;
            if (ch == '>') r[i].r = 2;
        }
        mem(err, -1);
        up(i, 0, N - 1) {
            init();
            up(j, 1, M) {
                if (i == r[j].u || i == r[j].v) continue;
                int x = find(r[j].u), y = find(r[j].v);
                if (x == y) {
                    if (val[r[j].v] != (val[r[j].u] + r[j].r) % 3) {
                        err[i] = j;
                        break;
                    }
                } else {
                    fa[y] = x;
                    val[y] = (val[r[j].u] - val[r[j].v] + r[j].r + 3) % 3;
                }
            }
        }
        int cnt = 0, ans1 = 0, ans2 = 0;
        up(i, 0, N - 1) {
            if (err[i] == -1) {
                ++cnt;
                ans1 = i;
            }
            ans2 = max(ans2, err[i]);
        }
        if (cnt == 0)
            printf("Impossible\n");
        else if (cnt > 1)
            printf("Can not determine\n");
        else
            printf(
                "Player %d can be determined to be the judge after %d lines\n",
                ans1, ans2);
    }

    return 0;
}