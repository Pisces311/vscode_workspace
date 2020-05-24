#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int n, k;
int l[maxn], r[maxn];
int w[maxn];
set<int> s;
vector<int> ans;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int p;
        cin >> p;
        s.insert(p);
    }
    if (!s.empty()) {
        auto it = s.begin();
        for (int i = 1; i <= n; ++i) {
            while (it != s.end() && *it < l[i]) ++it;
            while (it != s.end() && *it <= r[i]) {
                ++w[i];
                if (*it == r[i] && l[i + 1] == r[i]) ++w[i + 1];
                ++it;
            }
            if (w[i] > 2) {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int k = 2 - w[i];
        if (r[i] == l[i + 1]) {
            if (w[i + 1] < 2) {
                for (int j = r[i]; j >= l[i] && k; --j) {
                    if (s.find(j) == s.end()) {
                        ans.push_back(j);
                        if (j == r[i]) ++w[i + 1];
                        --k;
                    }
                }
            } else {
                for (int j = r[i] - 1; j >= l[i] && k; --j) {
                    if (s.find(j) == s.end()) {
                        ans.push_back(j);
                        --k;
                    }
                }
            }
        } else {
            for (int j = r[i]; j >= l[i] && k; --j) {
                if (s.find(j) == s.end()) {
                    ans.push_back(j);
                    --k;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << ' ';
    cout << '\n';

    return 0;
}