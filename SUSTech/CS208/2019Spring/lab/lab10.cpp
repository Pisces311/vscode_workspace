#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;

struct classroom {
    int stu, cap;
    bool operator<(const classroom& a) const {
        return cap == a.cap ? stu > a.stu : cap > a.cap;
    }
} a[maxn];

int N, sum = 0, cnt = 0;
int dp[2][maxn][maxn * maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    up(i, 1, N) scanf("%d %d", &a[i].stu, &a[i].cap);
    up(i, 1, N) sum += a[i].stu;
    sort(a + 1, a + N + 1);
    int tmp = sum;
    up(i, 1, N) {
        if (sum > 0) {
            sum -= a[i].cap;
            ++cnt;
        } else
            break;
    }
    int cap = 101 * cnt - tmp;
    up(i, 0, 1) up(j, 0, maxn - 1) {
        up(k, 0, maxn * maxn - 1) dp[i][j][k] = j == 0 ? 0 : -0x3f3f3f3f;
    }
    up(i, 1, N) up(j, 1, cnt) up(k, 1, cap) {
        int now = 101 - a[i].cap;
        if (now <= k) {
            if (dp[(i - 1) % 2][j][k] >
                dp[(i - 1) % 2][j - 1][k - now] + a[i].stu) {
                dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
            } else
                dp[i % 2][j][k] = dp[(i - 1) % 2][j - 1][k - now] + a[i].stu;
        } else {
            dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
        }
    }
    int ans = tmp - dp[N % 2][cnt][cap];
    printf("%d\n", ans);

    return 0;
}