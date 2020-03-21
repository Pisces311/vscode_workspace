#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

struct node {
    int coe, exp;
};

int T, n, m, q, query;
list<node> a, b, ans;

void init() {
    a.clear();
    b.clear();
    ans.clear();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        init();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int coe, exp;
            cin >> coe >> exp;
            a.push_back({coe, exp});
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            int coe, exp;
            cin >> coe >> exp;
            b.push_back({coe, exp});
        }
        auto i = a.begin(), j = b.begin();
        while (i != a.end() && j != b.end()) {
            if (i->exp == j->exp) {
                ans.push_back({i->coe + j->coe, i->exp});
                ++i;
                ++j;
            } else if (i->exp > j->exp) {
                ans.push_back(*j);
                ++j;
            } else {
                ans.push_back(*i);
                ++i;
            }
        }
        while (i != a.end()) {
            ans.push_back(*i);
            ++i;
        }
        while (j != b.end()) {
            ans.push_back(*j);
            ++j;
        }
        cin >> q;
        auto p = ans.begin();
        for (int i = 1; i <= q; ++i) {
            cin >> query;
            while (query > p->exp && p != ans.end()) ++p;
            if (p->exp != query)
                cout << "0 ";
            else
                cout << p->coe << ' ';
        }
        cout << '\n';
    }

    return 0;
}