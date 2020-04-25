#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int a[maxn];
vector<int> f, s, t;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        f.clear();
        s.clear();
        t.clear();
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 1)
                f.push_back(a[i]);
            else if (i % 3 == 2)
                s.push_back(a[i]);
            else
                t.push_back(a[i]);
        }
        for (int i : f) cout << i << ' ';
        cout << '\n';
        for (int i : s) cout << i << ' ';
        cout << '\n';
        for (int i : t) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}