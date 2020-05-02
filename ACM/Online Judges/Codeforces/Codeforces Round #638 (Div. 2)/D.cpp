#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, N;
vector<int> inc;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        inc.clear();
        cin >> N;
        for (int i = 1; i <= N; i *= 2) {
            inc.push_back(i);
            N -= i;
        }
        if (N) {
            inc.push_back(N);
            sort(inc.begin(), inc.end());
        }
        cout << inc.size() - 1 << '\n';
        for (int i = 1; i < inc.size(); ++i) cout << inc[i] - inc[i - 1] << ' ';
        cout << '\n';
    }

    return 0;
}