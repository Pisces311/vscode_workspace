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

const int maxn = 2e5 + 5;

int n, b, a;
int sun[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> b >> a;
    int cap = a;
    up(i, 1, n) cin >> sun[i];
    int dis = 0;
    up(i, 1, n) {
        if (a == cap)
            --a;
        else if (b == 0)
            --a;
        else if (!sun[i] && a)
            --a;
        else {
            --b;
            if (sun[i]) ++a;
        }
        if (b == 0 && a == 0 || i == n) {
            dis = i;
            break;
        }
    }
    cout << dis << endl;

    return 0;
}