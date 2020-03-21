#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;

struct node {
    int id, val;
} stk[maxn];

int t, n, top;
int a[maxn], l[maxn], r[maxn];

void solve(int s, int di, int *arr) {
    top = 0;
    for (int i = s; 1 <= i && i <= n; i += di) {
        if (top == 0) {
            arr[i] = 0;
            stk[++top] = {i, a[i]};
        } else {
            if (a[i] < stk[top].val) {
                arr[i] = 0;
                stk[++top] = {i, a[i]};
            } else {
                while (top && stk[top].val < a[i]) --top;
                arr[i] = stk[top + 1].id;
                stk[++top] = {i, a[i]};
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    int cas = 0;
    while (t--) {
        cout << "Case " << ++cas << ":\n";
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        solve(1, 1, l);
        solve(n, -1, r);
        for (int i = 1; i <= n; ++i) cout << l[i] << ' ' << r[i] << '\n';
    }

    return 0;
}