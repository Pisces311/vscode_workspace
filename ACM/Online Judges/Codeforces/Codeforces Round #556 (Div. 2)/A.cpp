#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 35;

int n, m, r;
int buy[maxn], sell[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    up(i, 1, n) cin >> buy[i];
    up(i, 1, m) cin >> sell[i];
    sort(buy + 1, buy + n + 1);
    sort(sell + 1, sell + m + 1);
    int re = r % buy[1];
    int num = r / buy[1];
    if (buy[1] >= sell[m])
        cout << r << endl;
    else
        cout << num * sell[m] + re << endl;

    return 0;
}