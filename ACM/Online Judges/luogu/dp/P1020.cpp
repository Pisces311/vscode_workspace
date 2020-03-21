#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int a[maxn];
int stk[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, n = 0;
    while (cin >> h) a[++n] = h;
    int top = 0;
    stk[++top] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] <= stk[top])
            stk[++top] = a[i];
        else {
            int p =
                upper_bound(stk + 1, stk + top + 1, a[i], greater<int>()) - stk;
            stk[p] = a[i];
        }
    }
    cout << top << '\n';
    top = 0;
    stk[++top] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] > stk[top])
            stk[++top] = a[i];
        else {
            int p = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
            stk[p] = a[i];
        }
    }
    cout << top << '\n';

    return 0;
}