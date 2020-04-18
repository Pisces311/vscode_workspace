#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct date {
    int y, m, d;
    bool mon;
    bool operator<(const date& a) const {
        if (y != a.y)
            return y < a.y;
        else if (m != a.m)
            return m < a.m;
        else
            return d < a.d;
    }
};

int T, y, m, d;
vector<date> v;
string name[] = {"",        "January",  "February", "March",  "April",
                 "May",     "June",     "July",     "August", "September",
                 "October", "November", "December"};

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int year = 2000, month = 5, day = 14;
    for (int i = 1; i < 200; ++i) {
        v.push_back({year, month, day, 1});
        year += 1;
        day -= 1;
        if (year % 4 == 0 && year % 100 != 0) day -= 1;
        if (day <= 7) day += 7;
    }
    year = 2000, month = 6, day = 18;
    for (int i = 1; i < 200; ++i) {
        v.push_back({year, month, day, 0});
        year += 1;
        day -= 1;
        if (year % 4 == 0 && year % 100 != 0) day -= 1;
        if (day <= 14) day += 7;
    }
    sort(v.begin(), v.end());
    cin >> T;
    while (T--) {
        cin >> y >> m >> d;
        int l = 0, ans = -1;
        while (v[l].y < y) ++l;
        for (int i = l; i < l + 2; ++i) {
            if (v[i].m > m) {
                ans = i;
                break;
            } else if (v[i].m == m && v[i].d > d) {
                ans = i;
                break;
            }
        }
        if (ans == -1) ans = l + 2;
        if (v[ans].mon) {
            cout << "Mother's Day: ";
        } else
            cout << "Father's Day: ";
        cout << name[v[ans].m] << ' ' << v[ans].d;
        int day = v[ans].d;
        if (day % 10 == 1 && day != 11)
            cout << "st, ";
        else if (day % 10 == 2 && day != 12)
            cout << "nd, ";
        else
            cout << "th, ";
        cout << v[ans].y << '\n';
    }

    return 0;
}