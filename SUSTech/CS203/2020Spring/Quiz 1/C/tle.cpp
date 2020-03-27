#include <math.h>

#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m, x;
int stk[maxn << 1], top = 0;
char op;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        stk[++top] = x;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> op;
        if (op == 'P')
            stk[++top] = x;
        else if (op == 'R')
            --top;
        else {
            int Max = 0;
            for (int j = 1; j <= top; ++j) Max = max(Max, stk[j]);
            cout << Max << '\n';
        }
    }

    return 0;
}