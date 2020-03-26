#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m, x;
stack<int> stk;
char op;

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/C/Input/test1.in", "r", stdin);
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/C/Output/test1.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        stk.push(x);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> op;
        if (op == 'P') {
            cin >> x;
            stk.push(max(x, stk.top()));
        } else if (op == 'R') {
            stk.pop();
        } else {
            cout << stk.top() << '\n';
        }
    }

    return 0;
}