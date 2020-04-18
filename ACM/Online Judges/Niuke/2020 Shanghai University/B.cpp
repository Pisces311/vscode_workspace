#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct report {
    int date, id;
    double temp;
    bool operator<(const report& a) const {
        if (date != a.date)
            return date > a.date;
        else if (temp != a.temp)
            return temp > a.temp;
        else
            return id < a.id;
    }
};

int n;
vector<report> v;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int date, id;
        double temp;
        cin >> date >> id >> temp;
        if (temp >= 38.0) {
            v.push_back({date, id, temp});
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (report i : v) {
        printf("%d %d %.1f\n", i.date, i.id, i.temp);
    }

    return 0;
}