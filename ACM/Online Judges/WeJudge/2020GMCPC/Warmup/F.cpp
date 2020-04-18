#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct node {
    int a, b, c;
    bool operator<(const node& other) const {
        if (a != other.a)
            return a < other.a;
        else
            return b < other.b;
    }
};

int num;
int a[maxn], tot = 0;
set<node> s;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> num && num != 0) a[++tot] = num;
    a[tot + 1] = 200;
    sort(a + 1, a + tot + 1);
    for (int i = 1; i <= tot; ++i) {
        for (int j = i + 1; j <= tot; ++j) {
            int tar = 100 - a[i] - a[j];
            int ak = *lower_bound(a + j + 1, a + tot + 1, tar);
            if (tar == ak) s.insert({a[i], a[j], tar});
        }
    }
    if (s.size())
        for (node i : s) cout << i.a << ' ' << i.b << ' ' << i.c << " \n";
    else
        cout << "NO\n";

    return 0;
}