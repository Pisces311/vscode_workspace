#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int a[maxn];
int Min[maxn][20], Max[maxn][20];

void init(int n) {
    for (int i = 1; i <= n; ++i) Min[i][0] = Max[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int qmax(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}

int qmin(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}