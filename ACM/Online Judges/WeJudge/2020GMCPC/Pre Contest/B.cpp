#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int y, m, d;
ll day;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool more(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> y >> m >> d) {
        day = 0;
        for (int i = 2000; i < y; ++i) {
            if (more(i))
                day += 366;
            else
                day += 365;
        }
        for (int i = 1; i < m; ++i) {
            if (i == 2 && more(y))
                day += 29;
            else
                day += month[i];
        }
        day += d;
        cout << (day - 1) / 4 + 1 << ' ' << (day % 4 == 0 ? 4 : day % 4)
             << '\n';
    }

    return 0;
}