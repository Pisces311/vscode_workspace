#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2.5e6 + 5;

struct query {
    int type, val;
} a[maxn];

int n, q;
int fa[maxn], dc[maxn], top = 0;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> a[i].type >> a[i].val;
        dc[++top] = a[i].val;
    }
    sort(dc + 1, dc + top + 1);
    if (dc[top] != n) dc[++top] = n;
    top = unique(dc + 1, dc + top + 1) - dc - 1;
    int m = top;
    for (int i = 2; i <= m; ++i)
        if (dc[i] - dc[i - 1] > 1) dc[++top] = dc[i - 1] + 1;
    sort(dc + 1, dc + top + 1);
    for (int i = 1; i <= top + 1; ++i) fa[i] = i;
    dc[top + 1] = -1;
    for (int i = 1; i <= q; ++i) {
        if (a[i].type == 1) {
            int pos = lower_bound(dc + 1, dc + top + 1, a[i].val) - dc;
            fa[pos] = pos + 1;
        } else {
            int pos = lower_bound(dc + 1, dc + top + 1, a[i].val) - dc;
            cout << dc[find(pos)] << '\n';
        }
    }

    return 0;
}