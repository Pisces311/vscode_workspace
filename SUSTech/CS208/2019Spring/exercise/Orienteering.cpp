#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define DEBUG
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e2 + 5;
const int maxm = 2e2 + 5;
const int maxk = 3e3 + 5;

struct node {
    int x, y, dis;
} q[41000];

int N, M, k, front, rear, ans = 0, vis_sign = 0, cnt = 0;
char g[maxn][maxm];
int vis[maxn][maxm];
int sx, sy;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    scanf("%d%d", &N, &M);
    up(i, 1, N) scanf("%s", g[i] + 1);
    scanf("%d", &k);
    sx = sy = 1;
    up(i, 1, k) {
        q[rear++] = {sx, sy, 0};
        scanf("%d%d", &sx, &sy);
        ++sx, ++sy;
        ++vis_sign;
        while (front != rear) {
            node f = q[front++];
            if (f.x == sx && f.y == sy) {
                ++cnt;
                ans += f.dis;
                break;
            }
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            up(i, 0, 3) {
                int x = f.x + dx[i], y = f.y + dy[i];
                if (vis[x][y] != vis_sign && g[x][y] == 'r') {
                    vis[x][y] = vis_sign;
                    q[rear++] = {x, y, f.dis + 1};
                }
            }
        }
        front = rear = 0;
    }
    if (cnt < k)
        print(-1);
    else
        print(ans);

    return 0;
}