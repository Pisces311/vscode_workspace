#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 1;

int n;
int xprf[maxn][maxn], yprf[maxn][maxn], inv[maxn][maxn];
int xmatch[maxn], ymatch[maxn], cnt[maxn];
queue<int> q;
map<string, int> xmap, ymap;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    string x[maxn], y[maxn];
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        xmap[x[i]] = i;
        for (int j = 1; j <= n; ++j) {
            if (i == 1) {
                cin >> y[j];
                ymap[y[j]] = j;
                xprf[i][j] = j;
            } else {
                string s;
                cin >> s;
                xprf[i][j] = ymap[s];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int u = ymap[s];
        for (int j = 1; j <= n; ++j) {
            string t;
            cin >> t;
            int v = xmap[t];
            yprf[u][j] = v;
            inv[u][v] = j;
        }
    }
    for (int i = 1; i <= n; ++i) q.push(i);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        while (!xmatch[f]) {
            int t = xprf[f][cnt[f] + 1];
            if (!ymatch[t]) {
                xmatch[f] = t;
                ymatch[t] = f;
            } else if (inv[t][ymatch[t]] > inv[t][f]) {
                q.push(ymatch[t]);
                xmatch[ymatch[t]] = 0;
                xmatch[f] = t;
                ymatch[t] = f;
            }
            ++cnt[f];
        }
    }
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ' << y[xmatch[i]] << '\n';

    return 0;
}