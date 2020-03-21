#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;

ll m;
vector<pii> p;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> m) {
        if (m == 0) {
            cout << "2\n1 1\n2 1\n";
            continue;
        }
        if (m == 1) {
            cout << "2\n1 199\n2 2\n";
            continue;
        }
        int cnt = 0, pos = 1;
        p.clear();
        while (m != 1) {
            if (m & 1) {
                p.push_back(make_pair(pos, 199));
                pos += 2;
                ++cnt;
            }
            p.push_back(make_pair(pos, pos + 2));
            p.push_back(make_pair(pos + 1, pos));
            pos += 3;
            cnt += 2;
            m /= 2;
        }
        cnt += 1;
        p.push_back(make_pair(pos - 1, 199));
        cout << cnt << '\n';
        for (pii i : p) cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}
