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

int T, n;
int need[maxn], has[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ll res = 0;
        up(i, 1, n) cin >> need[i];
        up(i, 1, n) cin >> has[i];
        bool ok = true;
        dn(i, n, 1) {
            res += has[i];
            if (res >= need[i])
                res -= need[i];
            else {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}