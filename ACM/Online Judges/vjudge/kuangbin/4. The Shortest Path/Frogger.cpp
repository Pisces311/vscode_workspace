#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <map>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 201;

struct node{
    int v;
    double w;
    friend bool operator<(const node& a, const node& b) { return a.w > b.w; }
};

int n, case_num = 0;
double ans;
int x[maxn], y[maxn];
bool vis[maxn];
priority_queue<node> pq;

inline void init(){
    ans = 0;
    memset(vis, false, sizeof(vis));
    while (!pq.empty()) pq.pop();
}

inline double getDis(int x, int y, int a, int b){
    return sqrt(pow((x - a), 2) + pow((y - b), 2));
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    while (~scanf("%d", &n) && n) {
        init();
        up(i, 1, n) scanf("%d %d", &x[i], &y[i]);
        pq.push({1, 0});
        while(1){
            node top = pq.top();
            pq.pop();
            if (vis[top.v]) continue;
            vis[top.v] = true;
            ans = max(ans, top.w);
            if (top.v == 2) break;
            up(i, 1, n)if(i!=top.v&&!vis[i]){
                double cur = getDis(x[i], y[i], x[top.v], y[top.v]);
                pq.push({i, cur});
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++case_num, ans);
    }

    return 0;
}