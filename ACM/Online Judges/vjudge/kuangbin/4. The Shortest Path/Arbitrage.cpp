#include <limits.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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

const int maxn = 35;

int n, m, cnt, case_cnt = 0;
double rate;
string s, _s;
map<string, int> ma;
string name[maxn];
vector<pair<int, double> > g[maxn];
bool vis[maxn];
double dis[maxn];
queue<int> q;

inline void init() {
    mem(vis, false);
    mem(dis, 0);
    ma.clear();
    cnt = 0;
    while(!q.empty())q.pop();
    up(i, 1, n)g[i].clear();
}

bool spfa() {
    dis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;
        up(i, 0, (int)g[f].size() - 1) {
            int v = g[f][i].first;
            if (dis[v] < dis[f] * g[f][i].second) {
                dis[v] = dis[f] * g[f][i].second;
                if (dis[1] > 1) return true;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> n && n != 0) {
        ++case_cnt;
        init();
        up(i, 1, n) {
            cin >> s;
            ma[s] = ++cnt;
            name[cnt] = s;
        }
        cin >> m;
        up(i, 1, m) {
            cin >> s >> rate >> _s;
            map<string, int>::iterator m1, m2;
            m1 = ma.find(s);
            m2 = ma.find(_s);
            g[m1->second].push_back({m2->second, rate});
        }
        if (spfa())
            cout << "Case " << case_cnt << ": Yes" << endl;
        else
            cout << "Case " << case_cnt << ": No" << endl;
    }

    return 0;
}