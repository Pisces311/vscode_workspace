#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

struct node {
    int id, w;
    bool operator<(const node& a) const { return w < a.w; }
} a[maxn];

int m, n, w, h;
int cur[maxn], d[maxn];
vector<node> available[maxn];
vector<int> ans[maxn];

bool check() {
    priority_queue<node> pq;
    for (int i = 1; i <= m; ++i) pq.push(a[i]);
    for (int i = 1; i <= n; ++i) {
        for (node u : available[i]) pq.push(u);
        while (cur[i] < d[i]) {
            if (pq.empty()) return false;
            node t = pq.top();
            pq.pop();
            ans[t.id].push_back(i);
            for (int j = i; j < i + w; ++j) ++cur[j];
            t.w -= w;
            if (t.w) available[i + w + h].push_back(t);
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> w >> h;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].w;
        a[i].id = i;
    }
    for (int i = 1; i <= n; ++i) cin >> d[i];
    if (check()) {
        cout << "1\n";
        for (int i = 1; i <= m; ++i) {
            for (int j : ans[i]) cout << j << ' ';
            cout << '\n';
        }
    } else
        cout << "-1\n";

    return 0;
}