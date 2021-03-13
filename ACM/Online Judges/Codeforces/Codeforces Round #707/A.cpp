#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 2e5 + 5;

struct node {
    int val, id;
    bool operator<(const node a) const { return val < a.val; }
} a[maxn];

int n;
vector<pii> sum[5000005];

bool check() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int tmp = a[i].val + a[j].val;
            if (sum[tmp].empty())
                sum[tmp].push_back(make_pair(a[i].id, a[j].id));
            else {
                pii f = sum[tmp].front();
                if (i == f.first || i == f.second || j == f.first ||
                    j == f.second)
                    continue;
                cout << "YES\n";
                cout << i << ' ' << j << ' ' << f.first << ' ' << f.second
                     << '\n';
                return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
    }
    if (!check()) cout << "NO\n";

    return 0;
}