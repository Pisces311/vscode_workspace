#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

//求区间和的线段树，区间修改、区间查询

struct SegTreeNode {
    int val, lazy;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = t[o << 1].val + t[o << 1 | 1].val;
}

void pushDown(int o, int l, int r) {
    if (t[o].lazy != 0) {
        t[o << 1].lazy += t[o].lazy;
        t[o << 1 | 1].lazy += t[o].lazy;
        t[o << 1].val += t[o].lazy;
        t[o << 1 | 1].val += t[o].lazy;
        t[o].lazy = 0;
    }
}

void build(int o, int arr[], int l, int r) {
    t[o].lazy = 0;
    if (l == r) {
        t[o].val = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    return (query(o << 1, l, mid, ql, qr) +
            query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].lazy += val;
        t[o].val += val * (r - l + 1);
        return;
    }
    pushDown(o, l, r);
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
    pushUp(o, l, r);
}