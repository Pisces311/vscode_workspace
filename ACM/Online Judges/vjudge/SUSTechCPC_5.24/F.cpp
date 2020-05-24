#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct node {
    int x, y, w;
};

int n, cnt;
int fa[maxn];
map<int, vector<int> > mp;
vector<node> ans;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void add(int x, int y, int w) {
    int u = find(x), v = find(y);
    if (u != v) {
        fa[u] = v, --cnt;
        ans.push_back({x, y, w});
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
    }
    for (auto it : mp) {
        vector<int>& e = it.second;
        for (int i = 1; i < e.size(); ++i) {
            add(e[i], e[i - 1], it.first);
        }
    }
    if (cnt != 1)
        cout << "impossible\n";
    else {
        for (auto w : ans) {
            cout << w.x << ' ' << w.y << ' ' << w.w << '\n';
        }
    }
    return 0;
}