#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int a[maxn], stk[maxn];

int lis(int l, int r) {
    int top = 0;
    for (int i = l; i <= r; ++i) {
        if (!top || a[i] > stk[top])
            stk[++top] = a[i];
        else {
            int p = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
            stk[p] = a[i];
        }
    }
    return top;
}