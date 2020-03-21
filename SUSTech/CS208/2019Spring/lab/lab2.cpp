#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e3 + 5;
const int maxm = 2e3 + 5;

struct grid {
    int x, y, dis;
} Hong;

int N, M;
char g[maxn][maxm];
int ng[maxn][maxm];                    // ng(new_graph)
bool fs[maxn][maxm], vis[maxn][maxm];  // fs(find_student)
priority_queue<grid> pq;

bool operator<(const grid& a, const grid& b) { return a.dis > b.dis; }

void get_new_graph() {
    up(i, 1, N) up(j, 1, M) {
        switch (g[i][j]) {
            case 'H':
                Hong = {i, j, 0};
                break;
            case 'S':
                fs[i][j] = true;
                break;
            case 'R':
                ng[i][j] = 1;
                break;
            case 'B':
                ng[i][j] = 2;
                break;
        }
    }
}

inline bool judge(int x, int y) {
    if (x >= 1 && x <= N && y >= 1 && y <= M && !vis[x][y]) return false;
    return true;
}

void bfs() {
    pq.push(Hong);
    vis[Hong.x][Hong.y] = true;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (pq.size()) {
        grid f = pq.top();
        pq.pop();
        up(i, 0, 3) {
            int x = f.x + dx[i], y = f.y + dy[i];
            if (judge(x, y)) continue;
            if (fs[x][y]) {
                cout << f.dis + 1 << endl;
                return;
            }
            if (ng[x][y]) {
                grid cur = {x, y, f.dis + ng[x][y]};
                ng[x][y] = 1;
                pq.push(cur);
                vis[x][y] = true;
            } else
                vis[x][y] = true;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("D:/in.txt", "r", stdin);
#endif

    cin >> N >> M;
    up(i, 1, N) cin >> g[i] + 1;
    get_new_graph();
    bfs();

    return 0;
}