#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n;
int q[maxn], ans[maxn];
bool check[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    cin >> n;
    up(i, 1, n - 1) cin >> q[i];
    up(i, 1, n - 1) ans[i + 1] = ans[i] + q[i];
    int mi = *min_element(ans + 1, ans + n + 1);
    up(i, 1, n) ans[i] = ans[i] - mi + 1;
    bool ok = true;
    up(i, 1, n) {
        if (ans[i] < 1 || ans[i] > n) {
            ok = false;
            break;
        }
        if (check[ans[i]] == false)
            check[ans[i]] = true;
        else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    up(i, 1, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}