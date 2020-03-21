#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 5;

int T, n;
char s[maxn];
stack<int> stk;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        while (stk.size()) stk.pop();
        cin >> n;
        cin >> (s + 1);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else {
                if (stk.empty()) {
                    ok = false;
                    break;
                }
                if (s[i] == ')' && stk.top() == '(')
                    stk.pop();
                else if (s[i] == ']' && stk.top() == '[')
                    stk.pop();
                else if (s[i] == '}' && stk.top() == '{')
                    stk.pop();
                else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && stk.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}