#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 55;

int n;
char g[maxn][maxn];

bool check(int i, int j) {
    if (g[i][j] == '#') return true;
    if (g[i][j] == '.' && g[i + 1][j] == '.' && g[i + 1][j - 1] == '.' &&
        g[i + 1][j + 1] == '.' && g[i + 2][j] == '.') {
        g[i][j] = '#';
        g[i + 1][j] = '#';
        g[i + 1][j - 1] = '#';
        g[i + 1][j + 1] = '#';
        g[i + 2][j] = '#';
        return true;
    }
    return false;
}

bool judge() {
    up(i, 1, n) up(j, 1, n) if (!check(i, j)) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) up(j, 1, n) cin >> g[i][j];
    if (judge())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}