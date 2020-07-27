#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

//储存元素出现个数
int num[maxn << 2];

void pushUp(int o, int l, int r) { num[o] = num[o << 1] + num[o << 1 | 1]; }

//查询ql到qr中元素个数
int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return num[o];
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

//查询第k大的元素
int query(int o, int l, int r, int k) {
    if (num[o] < k) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (k <= num[o << 1])
        return query(o << 1, l, mid, k);
    else
        return query(o << 1 | 1, mid + 1, r, k - num[o << 1]);
}

//元素p增加val
void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (l == r) {
        num[o] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}