#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;

void print(int x, int y) {
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i == x - 1 && j == y + 1 || i == x + 1 && j == y - 1) continue;
            cout << i << ' ' << j << '\n';
        }
    }
}

void add(int x, int y) {
    cout << x << ' ' << y << '\n';
    cout << x - 1 << ' ' << y << '\n';
    cout << x << ' ' << y - 1 << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cout << 3 * (n + 1) + 1 << '\n';
    print(1, 1);
    n -= 1;
    int x = 2, y = 2;
    while (n--) {
        ++x, ++y;
        add(x, y);
    }

    return 0;
}