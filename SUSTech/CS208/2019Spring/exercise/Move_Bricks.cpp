#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

struct task {
    int l, r, len;
    bool operator<(const task& a) const {
        if (len != a.len)
            return len > a.len;
        else
            return l > a.l;
    }
} a[maxn];

int N, Q, l, r;

bool judge(int mid) {
    int dn = -INT_MAX, le = -INT_MAX;
    int up = INT_MAX, ri = INT_MAX;
    up(i, 1, Q) {
        if (a[i].len <= mid) break;
        dn = max(dn, a[i].l + a[i].r - mid);
        le = max(le, -a[i].len - mid);
        up = min(up, a[i].l + a[i].r + mid);
        ri = min(ri, -a[i].len + mid);
    }
    if (dn <= up && le <= ri)
        return true;
    else
        return false;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    up(i, 1, Q) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        a[i] = {l, r, r - l};
    }
    sort(a + 1, a + Q + 1);
    l = 0, r = a[1].len;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << endl;

    return 0;
}