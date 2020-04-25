#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;

int n;
map<int, int> m;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++m[x];
    }
    int Max = 0, id = -1;
    for (auto i : m) {
        if (Max < i.second) {
            Max = i.second;
            id = i.first;
        }
    }
    cout << id << '\n';

    return 0;
}