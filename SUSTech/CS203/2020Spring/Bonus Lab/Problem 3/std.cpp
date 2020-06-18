#include <iostream>
#include <stack>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
stack<int> stk;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            stk.push(x);
        } else {
            cout << stk.top() << '\n';
            stk.pop();
        }
    }

    return 0;
}