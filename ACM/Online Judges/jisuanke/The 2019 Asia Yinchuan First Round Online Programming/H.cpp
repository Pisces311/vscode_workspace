#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int HP, ATK, t;
    bool operator<(const node& a) const { return t * a.ATK < a.t * ATK; }
} a[maxn];

int T, n;

int getTime(int HP) {
    int cnt = 0, dam = 1;
    while (HP > 0) {
        HP -= dam;
        ++cnt;
        ++dam;
    }
    return cnt;
}

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
        cout << "Case #" << ++cas << ": ";
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].HP >> a[i].ATK;
            a[i].t = getTime(a[i].HP);
        }
        sort(a + 1, a + n + 1);
        ll ans = 0, round = 0;
        for (int i = 1; i <= n; ++i) {
            round += a[i].t;
            ans += a[i].ATK * round;
        }
        cout << ans << '\n';
    }

    return 0;
}