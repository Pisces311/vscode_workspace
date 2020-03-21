#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int T, n, m, u, v, k, id;
vector<int> g[maxn], col;
bool vis[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(vis, false, sizeof(vis));
}

int main(int argc, char* argv[]) {
    FILE* f_in = fopen(argv[1], "r");    //测试输入
    FILE* f_out = fopen(argv[2], "r");   //测试输出
    FILE* f_user = fopen(argv[3], "r");  //用户输出
    int ret = 0;                         // AC=0,WA=1

    /*****spj代码区域*******/
    fscanf(f_in, "%d", &T);
    while (T--) {
        fscanf(f_in, "%d %d", &n, &m);
        init();
        for (int i = 1; i <= m; ++i) {
            fscanf(f_in, "%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        fscanf(f_user, "%d", &k);
        if (k < 1 || k > n / 2) {  //判断k的范围
            ret = 1;
            break;
        }
        while (k--) {
            if (fscanf(f_user, "%d", &id) == 1 && 1 <= id && id <= n &&
                vis[id] == false)  //有输出&&输出数的范围合法&&无重复
                vis[id] = true;
            else {
                ret = 1;
                break;
            }
        }
        if (ret) break;
        for (int u = 1; u <= n; ++u)
            if (!vis[u]) {
                bool ok = false;
                for (int v : g[u])
                    if (vis[v]) ok = true;
                if (!ok) {
                    ret = 1;
                    break;
                }
            }
    }

    /*****spj-end********/

    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}