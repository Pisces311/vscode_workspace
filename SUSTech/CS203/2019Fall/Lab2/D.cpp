#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int n, neg = 0, pos = 1e6 + 1, dif;
ll a[maxn];
ll M, ans = 0;

void find() {
    dif = n;
    for (int i = 1; i <= n; ++i)
        if (a[i] < 0)
            neg = i;
        else
            break;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            pos = i;
            break;
        }
    }
    for (int i = 2; i <= n; ++i)
        if (a[i] == a[i - 1]) --dif;
}

int cnt0() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!a[i]) ++cnt;
    return cnt;
}

void bin_pos(int id, int L, int R) {
    int l = L, r = R;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ll prod = a[id] * a[mid];
        if (prod == M) {
            ++ans;
            return;
        } else if (prod > M)
            r = mid - 1;
        else
            l = mid + 1;
    }
}

void bin_neg(int id, int L, int R) {
    int l = L, r = R;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ll prod = a[id] * a[mid];
        if (prod == M) {
            ++ans;
            return;
        } else if (prod > M)
            l = mid + 1;
        else
            r = mid - 1;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    find();
    if (!M) {
        int ret = cnt0();
        if (ret == 1)
            ans = dif - 1;
        else
            ans = dif;
    } else if (M > 0) {
        for (int i = pos; i <= n; ++i)
            if (i == pos || a[i] != a[i - 1]) bin_pos(i, i + 1, n);
        for (int i = 1; i <= neg; ++i)
            if (i == 1 || a[i] != a[i - 1]) bin_neg(i, i + 1, neg);
    } else {
        for (int i = 1; i <= neg; ++i)
            if (i == 1 || a[i] != a[i - 1]) bin_pos(i, pos, n);
    }
    cout << ans << '\n';

    return 0;
}