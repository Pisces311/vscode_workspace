#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
struct KM {
    int n;
    vector<int> cx, cy;  // 左右点的匹配对象
    vector<int> pre;
    vector<bool> visx, visy;
    vector<T> wx, wy;
    vector<vector<T> > g;
    vector<T> slack;
    T inf, res;
    queue<int> q;
    int org_n, org_m;

    KM(int _n, int _m) {
        org_n = _n;
        org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<T>::max();
        res = 0;
        g = vector<vector<T> >(n, vector<T>(n, -inf));
        cx = vector<int>(n, -1);
        cy = vector<int>(n, -1);
        pre = vector<int>(n);
        visx = vector<bool>(n);
        visy = vector<bool>(n);
        wx = vector<T>(n, -inf);
        wy = vector<T>(n);
        slack = vector<T>(n);
    }

    // custom
    void addEdge(int u, int v, int w) {
        g[u][v] = w;  // 负值还不如不匹配 因此设为0不影响
    }

    bool check(int v) {
        visy[v] = true;
        if (cy[v] != -1) {
            q.push(cy[v]);
            visx[cy[v]] = true;
            return false;
        }
        while (v != -1) {
            cy[v] = pre[v];
            swap(v, cx[pre[v]]);
        }
        return true;
    }

    void bfs(int i) {
        while (!q.empty()) q.pop();
        q.push(i);
        visx[i] = true;
        while (true) {
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; v++) {
                    if (!visy[v] && g[u][v] != -inf) {
                        T delta = wx[u] + wy[v] - g[u][v];
                        if (slack[v] >= delta) {
                            pre[v] = u;
                            if (delta) {
                                slack[v] = delta;
                            } else if (check(v)) {
                                return;
                            }
                        }
                    }
                }
            }
            // 没有增广路 修改顶标
            T a = inf;
            for (int j = 0; j < n; j++) {
                if (!visy[j]) {
                    a = min(a, slack[j]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (visx[j])  // S
                    wx[j] -= a;
                if (visy[j])  // T
                    wy[j] += a;
                else  // T'
                    slack[j] -= a;
            }
            for (int j = 0; j < n; j++) {
                if (!visy[j] && slack[j] == 0 && check(j)) {
                    return;
                }
            }
        }
    }

    void solve() {
        // 初始顶标
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != -inf) wx[i] = max(wx[i], g[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            fill(slack.begin(), slack.end(), inf);
            fill(visx.begin(), visx.end(), false);
            fill(visy.begin(), visy.end(), false);
            bfs(i);
        }

        // custom
        for (int i = 0; i < org_n; ++i) res += g[i][cx[i]];
        cout << res << '\n';
        for (int i = 0; i < org_m; i++) cout << cy[i] + 1 << ' ';
        cout << '\n';
    }
};