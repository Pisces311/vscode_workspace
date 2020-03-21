#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e1 + 5;

int q[5];
int special[] = {0, 4, 8, 15, 16, 23, 42}, ans[maxn];

inline bool check(int i) {
    up(j, 1, 4) {
        if (q[j] % special[i] != 0) return false;
        int quo = q[j] / special[i];
        bool found = false;
        up(k, 1, 6) if (special[k] == quo) found = true;
        if (!found) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &q[1]);
    if (q[1] == 0) return 0;
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d", &q[2]);
    if (q[2] == 0) return 0;
    printf("? 1 4\n");
    fflush(stdout);
    scanf("%d", &q[3]);
    if (q[3] == 0) return 0;
    printf("? 1 5\n");
    fflush(stdout);
    scanf("%d", &q[4]);
    if (q[4] == 0) return 0;
    up(i, 1, 6) {
        if (check(i)) {
            ans[1] = special[i];
            break;
        }
    }
    ans[2] = q[1] / ans[1];
    ans[3] = q[2] / ans[1];
    ans[4] = q[3] / ans[1];
    ans[5] = q[4] / ans[1];
    ans[6] =
        4 * 8 * 15 * 16 * 23 * 42 / ans[1] / ans[2] / ans[3] / ans[4] / ans[5];
    printf("! ");
    up(i, 1, 6) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}