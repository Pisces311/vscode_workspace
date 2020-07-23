#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e1 + 5;

struct Item {
    ll a, b, c, d;
    bool operator<(const Item& rhs) const {
        return a < rhs.a && b < rhs.b && c < rhs.c && d < rhs.d;
    }
} item[maxn];

int T, n, k, level;
ll ans;
vector<int> type[maxn];
vector<Item> v, g;
bool vis[100005];

inline void init() {
    level = 1;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= k; ++i) type[i].clear();
    v.clear();
    g.clear();
}

void collect(int depth, ll a, ll b, ll c, ll d) {
    if (type[depth].empty()) {
        if (depth != level)
            collect(depth + 1, a, b, c, d);
        else
            v.push_back({a, b, c, d});
    } else {
        for (int i : type[depth]) {
            if (depth != level)
                collect(depth + 1, a + item[i].a, b + item[i].b, c + item[i].c,
                        d + item[i].d);
            else
                v.push_back({a + item[i].a, b + item[i].b, c + item[i].c,
                             d + item[i].d});
        }
    }
}

void dfs(int depth, ll a, ll b, ll c, ll d) {
    if (type[depth].empty()) {
        if (depth != k)
            dfs(depth + 1, a, b, c, d);
        else
            ans = max(ans, a * b * c * d);
    } else {
        for (int i : type[depth]) {
            if (depth != k)
                dfs(depth + 1, a + item[i].a, b + item[i].b, c + item[i].c,
                    d + item[i].d);
            else
                ans = max(ans, (a + item[i].a) * (b + item[i].b) *
                                   (c + item[i].c) * (d + item[i].d));
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // time_t begin_t = clock();

    cin >> T;
    while (T--) {
        cin >> n >> k;
        init();
        for (int i = 1; i <= n; ++i) {
            int t;
            cin >> t >> item[i].a >> item[i].b >> item[i].c >> item[i].d;
            type[t].push_back(i);
        }
        int sum = type[level].size();
        while (sum < 20) {
            ++level;
            sum += type[level].size();
        }
        ans = 0;
        collect(1, 100, 100, 100, 100);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[i] < v[j])
                    vis[i] = true;
                else if (v[j] < v[i])
                    vis[j] = true;
            }
        }
        for (int i = 0; i < v.size(); ++i)
            if (!vis[i]) g.push_back(v[i]);
        for (Item i : g) dfs(level + 1, i.a, i.b, i.c, i.d);
        cout << ans << '\n';
    }

    // time_t finish_t = clock();
    // cout << "Time cost: " << (double)(finish_t - begin_t) / CLOCKS_PER_SEC
    //      << 's\n';

    return 0;
}