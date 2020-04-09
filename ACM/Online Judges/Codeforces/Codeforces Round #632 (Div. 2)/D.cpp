#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e3 + 5;

struct op {
    int id, depth;
};

int n, k;
char s[maxn];
queue<op> q;
vector<int> order[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> (s + 1);
    for (int i = 1; i <= n; ++i)
        if (s[i] == 'R' && s[i + 1] == 'L') q.push({i, 1});
    int num = 0, max_dep = 0;
    while (!q.empty()) {
        op u = q.front();
        q.pop();
        s[u.id] = 'L', s[u.id + 1] = 'R';
        order[u.depth].push_back(u.id);
        ++num;
        max_dep = max(max_dep, u.depth);
        if (s[u.id - 1] == 'R') q.push({u.id - 1, u.depth + 1});
        if (s[u.id + 2] == 'L') q.push({u.id + 1, u.depth + 1});
    }
    if (num < k || max_dep > k)
        cout << "-1\n";
    else {
        for (int i = 1; i <= max_dep; ++i) {
            for (int j = 0; j < order[i].size(); ++j) {
                int level = max_dep - i + 1;
                if (j == order[i].size() - 1) level--;
                if (level <= k - 1) {
                    cout << "1 " << order[i][j] << '\n';
                    --k;
                } else {
                    cout << order[i].size() - j << ' ';
                    for (int k = j; k < order[i].size(); ++k)
                        cout << order[i][k] << ' ';
                    cout << '\n';
                    --k;
                    break;
                }
            }
        }
    }

    return 0;
}