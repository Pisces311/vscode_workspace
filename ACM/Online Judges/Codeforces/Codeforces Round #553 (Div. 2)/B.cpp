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

const int maxn = 505;
const int maxm = 505;

int n, m, cur = 0;
int a[maxn][maxm];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    int px = -1, py = -1;
    cin >> n >> m;
    up(i, 1, n) up(j, 1, m) cin >> a[i][j];
    up(i, 1, n) cur ^= a[i][1];
    for (int i = 1; i <= n && px == -1; ++i) up(j, 1, m) {
            int nxt = cur ^ a[i][1] ^ a[i][j];
            if (nxt > 0) {
                px = i;
                py = j;
                break;
            }
        }
    if (px != -1 && py != -1) {
        cout << "TAK" << endl;
        up(i, 1, n) cout << (i == px ? py : 1) << ' ';
        cout << endl;
    } else
        cout << "NIE" << endl;

    return 0;
}