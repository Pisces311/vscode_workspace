#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e3 + 5;

int n, m, top = 0;
char g[maxn][maxn];
int Up[maxn][maxn], s[maxn], pos[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> (g[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j] == '1') Up[i][j] = Up[i - 1][j] + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l_p = 0;
        for (int j = 1; j <= m + 1; j++) {
            int p = j;
            while (top != 0 && s[top] > Up[i][j]) {
                if (pos[top] <= l_p) ++ans;
                p = pos[top];
                top--;
            }
            if (!Up[i + 1][j]) l_p = j;
            if (Up[i][j] && (top == 0 || s[top] < Up[i][j])) {
                s[++top] = Up[i][j];
                pos[top] = p;
            }
        }
        top = 0;
    }
    cout << ans << '\n';

    return 0;
}