#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct query {
    int l, r, in;
} q[maxn];

int N, M, K, block, ans;
int a[maxn], anss[maxn], sum[maxn];

bool cmp(const query& a, const query& b) {
    return (a.r / block) == (b.r / block) ? a.l < b.l : a.r < b.r;
}

inline void add(int x) {
    sum[a[x]]++;
    ans += 2 * sum[a[x]] - 1;  //可修改的操作
}

inline void del(int x) {
    sum[a[x]]--;
    ans -= 2 * sum[a[x]] + 1;  //可修改的操作
}

//若N和M同阶，则可直接取block=sqrt(N). 如果M特别大，则取block=N/sqrt(M).
//虽然实际上block=N/sqrt(M*2/3)可能会更快。
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    block = sqrt(N);
    for (int i = 1; i <= M; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].in = i;
    }
    sort(q + 1, q + M + 1, cmp);
    int l = 0, r = 0;
    for (int i = 1; i <= M; ++i) {
        int ql = q[i].l, qr = q[i].r;
        while (l < ql) del(l++);
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (r > qr) del(r--);
        anss[q[i].in] = ans;
    }
    for (int i = 1; i <= M; ++i) cout << anss[i] << '\n';

    return 0;
}