#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    char ch;
    int id;
    bool operator<(const node& a) const { return id < a.id; }
};

vector<node> v;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    cout << 20 << '\n';
    for (int i = 1; i <= 5; ++i) {
        int a = rint(1, 1e6), b = rint(a + 1, 2e6), c = rint(b + 1, 3e6),
            d = rint(c + 1, 4e6);
        v.push_back({'2', a});
        v.push_back({'0', b});
        v.push_back({'2', c});
        v.push_back({'0', d});
    }
    sort(v.begin(), v.end());
    for (node i : v) cout << i.ch;
    cout << '\n';

    return 0;
}