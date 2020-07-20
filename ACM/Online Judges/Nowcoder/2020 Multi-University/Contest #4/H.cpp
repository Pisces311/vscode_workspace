#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, gcnt;
vector<int> group[maxn];
int cnt[maxn];
bool vis[maxn];
vector<int> ansx, ansy;

inline void init() {
    gcnt = 0;
    ansx.clear(), ansy.clear();
    memset(vis + 1, false, sizeof(bool) * n);
    memset(cnt + 1, 0, sizeof(int) * n);
}

int get(int i) {
    while (!group[i].empty()) {
        int ret = group[i].back();
        group[i].pop_back();
        if (!vis[ret]) return ret;
    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 2; i <= n; ++i) {
            if (!cnt[i]) {
                ++gcnt;
                for (int j = 1; i * j <= n; ++j) {
                    group[gcnt].push_back(i * j);
                    ++cnt[i * j];
                }
            }
        }
        for (int i = gcnt; i >= 1; --i) {
            sort(group[i].begin(), group[i].end(),
                 [](int x, int y) { return cnt[x] > cnt[y]; });
            while (group[i].size() > 1) {
                int x = get(i), y = get(i);
                if (x != -1 && y != -1) {
                    vis[x] = true, vis[y] = true;
                    ansx.push_back(x);
                    ansy.push_back(y);
                }
            }
        }
        cout << ansx.size() << '\n';
        for (int i = 0; i < ansx.size(); ++i)
            cout << ansx[i] << ' ' << ansy[i] << '\n';
        for (int i = 1; i <= gcnt; ++i) group[i].clear();
    }

    return 0;
}