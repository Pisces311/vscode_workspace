#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int n;
int a[maxn];
multiset<int> b;

bool check(int i) {
    b.clear();
    for (int i = 1; i <= 2 * n; ++i) b.insert(a[i]);
    int sum = a[2 * n];
    b.erase(b.find(a[i]));
    b.erase(b.find(a[2 * n]));
    while (!b.empty()) {
        int find = sum - *b.rbegin();
        sum = *b.rbegin();
        b.erase(b.find(*b.rbegin()));
        auto x = b.find(find);
        if (x == b.end())
            return false;
        else
            b.erase(x);
    }
    return true;
}

pair<int, int> solve() {
    for (int i = 1; i < 2 * n; ++i) {
        if (check(i)) return make_pair(a[i] + a[2 * n], a[i]);
    }
    return make_pair(-1, -1);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        auto ret = solve();
        if (ret.first != -1) {
            cout << "YES\n";
            cout << ret.first << '\n';
            b.clear();
            for (int i = 1; i <= 2 * n; ++i) b.insert(a[i]);
            int sum = a[2 * n];
            cout << ret.second << ' ' << a[2 * n] << '\n';
            b.erase(b.find(ret.second));
            b.erase(b.find(a[2 * n]));
            while (!b.empty()) {
                int find = sum - *b.rbegin();
                cout << find << ' ' << *b.rbegin() << '\n';
                sum = *b.rbegin();
                b.erase(b.find(*b.rbegin()));
                auto x = b.find(find);
                b.erase(x);
            }
        } else
            cout << "NO\n";
    }

    return 0;
}