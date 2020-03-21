#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

int T, n, m;
ll a[maxn], b[maxn];
ll a0[maxn], a1[maxn], b0[maxn], b1[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        up(i, 1, n) cin >> a[i];
        up(i, 1, m) cin >> b[i];
        int pref, topa1 = 0, topa0 = 0, topb1 = 0, topb0 = 0;
        int cnt = 0;
        up(i, 1, n) {
            cin >> pref;
            if (pref != 0)
                a1[++topa1] = a[i];
            else
                a0[++topa0] = a[i];
        }
        up(i, 1, m) {
            cin >> pref;
            if (pref != 0)
                b1[++topb1] = b[i];
            else
                b0[++topb0] = b[i];
        }
        sort(a0 + 1, a0 + topa0 + 1);
        sort(a1 + 1, a1 + topa1 + 1);
        sort(b0 + 1, b0 + topb0 + 1);
        sort(b1 + 1, b1 + topb1 + 1);
        int cnt1 = 1, cnt2 = 1;
        up(i, 1, topb0) {
            if (cnt1 > topa1) break;
            if (a1[cnt1] < b0[i]) {
                ++cnt;
                ++cnt1;
            }
        }
        up(i, 1, topa0) {
            if (cnt2 > topb1) break;
            if (b1[cnt2] < a0[i]) {
                ++cnt;
                ++cnt2;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}