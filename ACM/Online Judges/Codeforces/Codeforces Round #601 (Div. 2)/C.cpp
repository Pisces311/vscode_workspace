#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;

int n;
int a[5], cnt[maxn];
map<pii, pii> m;
queue<int> ans;

void insert(int x, int y, int z) {
    pii p = make_pair(x, y);
    if (!m[p].first)
        m[p].first = z;
    else
        m[p].second = z;
}

void solve(int fi, int se) {
    ans.push(se);
    int prev = -1;
    while (ans.size() != n) {
        pii p = make_pair(min(fi, se), max(fi, se));
        pii ret = m[p];
        if (ret.first != prev) {
            ans.push(ret.first);
            prev = fi;
            fi = se;
            se = ret.first;
        } else {
            ans.push(ret.second);
            prev = fi;
            fi = se;
            se = ret.second;
        }
    }
    while (ans.size()) {
        cout << ans.front() << ' ';
        ans.pop();
    }
    cout << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 2; ++i) {
        cin >> a[1] >> a[2] >> a[3];
        ++cnt[a[1]], ++cnt[a[2]], ++cnt[a[3]];
        sort(a + 1, a + 4);
        insert(a[1], a[2], a[3]);
        insert(a[1], a[3], a[2]);
        insert(a[2], a[3], a[1]);
    }
    int find_1 = -1, find_21 = -1, find_22 = -1;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == 1 && find_1 == -1)
            find_1 = i;
        else if (cnt[i] == 2 && find_21 == -1)
            find_21 = i;
        else if (cnt[i] == 2 && find_22 == -1)
            find_22 = i;
    ans.push(find_1);
    if (m[make_pair(min(find_1, find_21), max(find_1, find_21))].first)
        solve(find_1, find_21);
    else
        solve(find_1, find_22);

    return 0;
}