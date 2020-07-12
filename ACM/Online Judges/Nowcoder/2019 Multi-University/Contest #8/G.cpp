#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

char s[maxn];
char stk[maxn];
int top = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> (s + 1);
    int len = strlen(s + 1);
    int cnt = 0;
    for (int i = 1; i <= len; ++i) {
        stk[++top] = s[i];
        while (top >= 3 && stk[top] == stk[top - 1] &&
               stk[top - 1] == stk[top - 2]) {
            top -= 3;
            ++cnt;
        }
    }
    cout << cnt << '\n';

    return 0;
}