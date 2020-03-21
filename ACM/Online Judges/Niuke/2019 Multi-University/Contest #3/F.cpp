#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e2 + 5;

struct node {
    int p, v;
} q1[maxn], q2[maxn];

int T, n, m;
int g[maxn][maxn];
int r1, r2, ans;
int f1, f2;
int Max[505], Min[505];

void solve(int i, int j) {
    r1 = r2 = 0;
    f1 = f2 = 0;
    int max_len = 0;
    int l = 1;
    for (int k = 1; k <= n; k++) {
        Max[k] = max(Max[k], g[j][k]);
        Min[k] = min(Min[k], g[j][k]);
        if (r1 == f1 || Max[k] < q1[r1 - 1].v) {
            q1[r1++] = {k, Max[k]};
        } else {
            while (r1 > f1 && Max[k] >= q1[r1 - 1].v) r1--;
            q1[r1++] = {k, Max[k]};
        }
        if (r2 == f2 || Min[k] > q2[r2 - 1].v) {
            q2[r2++] = {k, Min[k]};
        } else {
            while (r2 > f2 && Min[k] <= q2[r2 - 1].v) r2--;
            q2[r2++] = {k, Min[k]};
        }
        while (l <= k && q1[f1].v - q2[f2].v > m) {
            l = min(q1[f1].p, q2[f2].p);
            if (f1 < r1 && q1[f1].p == l) f1++;
            if (f2 < r2 && q2[f2].p == l) f2++;
            l++;
        }
        max_len = max(k - l + 1, max_len);
    }
    ans = max(ans, (j - i + 1) * max_len);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);
        ans = 1;
        for (int i = 1; i <= n; i++) {
            memset(Max, 0, sizeof(Max));
            memset(Min, 25, sizeof(Min));
            for (int j = i; j <= n; j++) solve(i, j);
        }
        printf("%d\n", ans);
    }

    return 0;
}