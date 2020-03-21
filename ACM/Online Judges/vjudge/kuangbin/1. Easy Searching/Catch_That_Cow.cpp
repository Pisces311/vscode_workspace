#include <stdio.h>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int p, w;
};

int N, K;
bool vis[maxn];

void bfs() {
    queue<node> q;
    q.push({N, 0});
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        if (f.p == K) {
            printf("%d\n", f.w);
            return;
        }
        if (vis[f.p]) continue;
        vis[f.p] = true;
        if (f.p >= 1) q.push({f.p - 1, f.w + 1});
        if (f.p <= 99999) q.push({f.p + 1, f.w + 1});
        if (f.p <= 50000) q.push({2 * f.p, f.w + 1});
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &K);
    bfs();

    return 0;
}