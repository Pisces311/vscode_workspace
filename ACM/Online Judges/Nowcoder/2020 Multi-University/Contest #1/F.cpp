#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

string a, b;

int cmp() {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> a >> b) {
        a += a;
        b += b;
        if (a.size() < b.size())
            while (a.size() < b.size()) a += a;
        else if (a.size() > b.size())
            while (a.size() > b.size()) b += b;
        int ret = cmp();
        if (ret == -1)
            cout << "<\n";
        else if (ret == 1)
            cout << ">\n";
        else
            cout << "=\n";
    }

    return 0;
}