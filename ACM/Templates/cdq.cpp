#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int maxk = 2e5 + 5;

// b为原数组，a为去重后的数组
struct node {
    int x, y, z, ans, w;
    bool operator==(const node& a) const {
        return x == a.x && y == a.y && z == a.z;
    }
} a[maxn], b[maxn];

int n, k, m = 0;
int cnt[maxn], c[maxk];

bool cmpx(node a, node b) {
    if (a.x == b.x)
        return a.y == b.y ? a.z < b.z : a.y < b.y;
    else
        return a.x < b.x;
}

bool cmpy(node a, node b) { return a.y == b.y ? a.z < b.z : a.y < b.y; }

int lowbit(int x) { return x & (-x); }

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

int getSum(int l, int r) { return sum(r) - sum(l - 1); }

void update(int x, int val) {
    for (int i = x; i <= k; i += lowbit(i)) c[i] += val;
}

// 复杂度：O(nlognlogk)
void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(a + l, a + mid + 1, cmpy);
    sort(a + mid + 1, a + r + 1, cmpy);
    int i = l, j = mid + 1;
    for (; j <= r; ++j) {
        while (a[i].y <= a[j].y && i <= mid) update(a[i].z, a[i].w), ++i;
        a[j].ans += getSum(1, a[j].z);
    }
    for (j = l; j < i; ++j) update(a[j].z, -a[j].w);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> b[i].x >> b[i].y >> b[i].z;
    sort(b + 1, b + n + 1, cmpx);
    for (int i = 1; i <= n; ++i) {
        int num = 1;
        while (i < n && b[i + 1] == b[i]) ++num, ++i;
        a[++m] = b[i], a[m].w = num;
    }
    cdq(1, m);
    for (int i = 1; i <= m; ++i) cnt[a[i].ans + a[i].w] += a[i].w;
    for (int i = 1; i <= n; ++i) cout << cnt[i] << '\n';

    return 0;
}