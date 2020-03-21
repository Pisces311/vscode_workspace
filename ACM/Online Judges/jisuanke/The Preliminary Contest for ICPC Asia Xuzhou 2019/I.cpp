#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct sum {
    int l, r, id;
    bool operator<(const sum& a) const { return l < a.l; }
} q[maxn];

int n, m;
int psum[maxn], pos[maxn], ans[maxn], c[maxn];
vector<int> R[maxn];

int lowbit(int x) { return x & (-x); }

void udpate(int x, int val) {
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
}

int sum(int p) {
    int res = 0;
    while (p) {
        res += c[p];
        p -= lowbit(p);
    }
    return res;
}

int getSum(int l, int r) { return sum(r) - sum(l - 1); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        pos[val] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (int i = 1; i <= n; ++i) {
        int tmp = i;
        while (tmp <= n) {
            int l = min(pos[i], pos[tmp]), r = max(pos[i], pos[tmp]);
            R[l].push_back(r);
            ++psum[r];
            tmp += i;
        }
    }
    for (int i = 1; i <= n; ++i) psum[i] += psum[i - 1];
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= m && q[j].l == i) {
            ans[q[j].id] = getSum(q[j].l, q[j].r);
            ++j;
        }
        for (int k : R[i]) udpate(k, 1);
    }
    int l, r;
    for (int i = 1; i <= m; ++i) {
        l = q[i].l, r = q[i].r;
        ans[q[i].id] = psum[r] - psum[l - 1] - ans[q[i].id] - (r - l + 1);
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';

    return 0;
}