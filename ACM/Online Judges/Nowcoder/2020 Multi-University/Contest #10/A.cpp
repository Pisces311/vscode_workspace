#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int T, p;
bool vis[maxn];
vector<int> ans;

bool solve() {
    ans.clear();
    int s = 1;
    vis[s] = true;
    ans.push_back(s);
    for (int i = 2; i <= p - 1; ++i) {
        if (!vis[s * 3 % p] && (s * 3 % p)) {
            s = s * 3 % p;
            vis[s] = true;
            ans.push_back(s);
        } else if (!vis[s * 2 % p] && (s * 2 % p)) {
            s = s * 2 % p;
            vis[s] = true;
            ans.push_back(s);
        } else {
            return false;
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

    cin >> T;
    while (T--) {
        cin >> p;
        memset(vis + 1, false, sizeof(bool) * p);
        if (solve()) {
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        } else
            cout << "-1\n";
    }

    return 0;
}