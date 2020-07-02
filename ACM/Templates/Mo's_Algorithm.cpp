#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, M, K, block, res;
int a[maxn], ans[maxn], sum[maxn];

struct query {
    int l, r, in;
    bool operator<(const query& a) const {
        return (r / block) == (a.r / block) ? l < a.l : r < a.r;
    }
} q[maxn];

inline void add(int x) {
    sum[a[x]]++;
    res += 2 * sum[a[x]] - 1;  //可修改的操作
}

inline void del(int x) {
    sum[a[x]]--;
    res -= 2 * sum[a[x]] + 1;  //可修改的操作
}

//若N和M同阶，则可直接取block=sqrt(N). 如果M特别大，则取block=N/sqrt(M).
//虽然实际上block=N/sqrt(M*2/3)可能会更快。
int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    block = sqrt(N);
    for (int i = 1; i <= M; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].in = i;
    }
    sort(q + 1, q + M + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= M; ++i) {
        int ql = q[i].l, qr = q[i].r;
        while (l < ql) del(l++);
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (r > qr) del(r--);
        ans[q[i].in] = res;
    }
    for (int i = 1; i <= M; ++i) cout << ans[i] << '\n';

    return 0;
}