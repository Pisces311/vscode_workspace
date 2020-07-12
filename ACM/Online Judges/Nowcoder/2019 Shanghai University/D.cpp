#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int len;
char s[maxn];
int num[maxn][105];
char ans[105], tot = 0;
stack<int> stk;
bool in[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> (s + 1);
    len = strlen(s + 1);
    for (int i = len; i >= 1; --i) {
        for (int j = 1; j <= 100; ++j) num[i][j] = num[i + 1][j];
        ++num[i][s[i] - '!' + 1];
    }
    stk.push(s[1]);
    in[s[1] - '!' + 1] = true;
    for (int i = 2; i <= len; ++i) {
        int p = s[i] - '!' + 1;
        if (in[p]) continue;
        while (!stk.empty() && s[i] < stk.top() &&
               num[i][stk.top() - '!' + 1]) {
            in[stk.top() - '!' + 1] = false;
            stk.pop();
        }
        stk.push(s[i]);
        in[p] = true;
    }
    while (!stk.empty()) {
        ans[++tot] = stk.top();
        stk.pop();
    }
    reverse(ans + 1, ans + tot + 1);
    cout << (ans + 1) << '\n';

    return 0;
}