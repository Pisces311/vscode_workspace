#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct student {
    int id, C, math, english, sum;
    bool operator<(const student& a) const {
        if (sum != a.sum) {
            return sum > a.sum;
        } else if (C != a.C) {
            return C > a.C;
        } else
            return id < a.id;
    }
} a[maxn];

int n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].id = i;
        cin >> a[i].C >> a[i].math >> a[i].english;
        a[i].sum = a[i].C + a[i].math + a[i].english;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= 5; ++i)
        cout << a[i].id << ' ' << a[i].C << ' ' << a[i].math << ' '
             << a[i].english << '\n';

    return 0;
}