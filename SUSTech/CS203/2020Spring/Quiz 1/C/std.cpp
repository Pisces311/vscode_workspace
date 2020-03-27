#include <assert.h>

#include <iostream>
#include <stack>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m, x;
stack<int> stk;
char op;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    assert(n <= 1e5 && m <= 1e5);
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
            assert(stk.size());
            stk.pop();
        } else {
            assert(stk.size());
            cout << stk.top() << '\n';
        }
    }

    return 0;
}