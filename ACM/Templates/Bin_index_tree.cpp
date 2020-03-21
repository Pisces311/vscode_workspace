#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
int c[maxn];

int lowbit(int x) { return x & (-x); }

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

int getSum(int l, int r) { return sum(r) - sum(l - 1); }

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += val;
}