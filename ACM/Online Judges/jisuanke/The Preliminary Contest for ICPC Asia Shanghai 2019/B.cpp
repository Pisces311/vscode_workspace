#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int T, N, M, L, R, tot, ans;
int bound[maxn];

inline void init() { tot = ans = 0; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cin >> N >> M;
        init();
        while (M--) {
            cin >> L >> R;
            bound[++tot] = L;
            bound[++tot] = R + 1;
        }
        sort(bound + 1, bound + tot + 1);
        for (int i = 1; i <= tot - 1; i += 2) ans += bound[i + 1] - bound[i];
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }

    return 0;
}