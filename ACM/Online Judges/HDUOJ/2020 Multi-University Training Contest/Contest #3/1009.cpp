#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
char s[maxn];
int que[maxn];
stack<int> stk;

bool solve() {
    while (!stk.empty()) stk.pop();
    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*')
            que[++r] = i;
        else if (s[i] == '(')
            stk.push(i);
        else if (stk.empty()) {
            if (l <= r)
                s[que[l++]] = '(';
            else
                return false;
        } else
            stk.pop();
    }
    while (!stk.empty()) {
        if (l <= r && que[r] > stk.top()) {
            s[que[r--]] = ')';
            stk.pop();
        } else
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        if (!solve())
            cout << "No solution!\n";
        else {
            for (int i = 1; i <= n; ++i)
                if (s[i] != '*') cout << s[i];
            cout << '\n';
        }
    }

    return 0;
}