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

const int maxn = 1e2 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int D;
    bool ok = true;
    if ((a[n] - a[1]) & 1) {
        D = a[n] - a[1];
        int tar = a[1];
        up(i, 1, n) {
            if (a[i] != tar && a[i] - D != tar) ok = false;
        }
    } else {
        D = (a[n] - a[1]) / 2;
        int tar = (a[n] + a[1]) / 2;
        up(i, 1, n) {
            if (a[i] != tar && a[i] + D != tar && a[i] - D != tar) ok = false;
        }
    }
    if (ok)
        cout << D << endl;
    else
        cout << -1 << endl;

    return 0;
}