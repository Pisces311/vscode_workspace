#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int T, N;
int e[maxn];

int solve() {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int st = i, ed = i + e[i] - 1;
        if (ed > N) return ans;
        while (e[ed] > ed - st + 1) {
            ed = st + e[ed] - 1;
            if (ed > N) return ans;
        }
        ++ans;
        i = ed;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> e[i];
        sort(e + 1, e + N + 1);
        cout << solve() << '\n';
    }

    return 0;
}