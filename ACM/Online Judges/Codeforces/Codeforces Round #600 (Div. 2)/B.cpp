#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
int a[maxn], employ[1000005];
bool enter[1000005];
vector<int> ans;

bool solve() {
    vector<int> en;
    int in = 0, last = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            if (employ[a[i]])
                return false;
            else {
                if (enter[a[i]]) return false;
                ++employ[a[i]];
                ++in;
            }
        } else {
            a[i] = -a[i];
            if (!employ[a[i]])
                return false;
            else {
                --employ[a[i]];
                --in;
                enter[a[i]] = true;
                en.push_back(a[i]);
                if (!in) {
                    for (int j : en) enter[j] = false;
                    en.clear();
                    ans.push_back(i - last);
                    last = i;
                }
            }
        }
    }
    if (in) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (solve()) {
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    } else
        cout << "-1\n";

    return 0;
}