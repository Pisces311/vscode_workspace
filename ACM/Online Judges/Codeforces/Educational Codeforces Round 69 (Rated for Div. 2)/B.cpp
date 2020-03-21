#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n;
int ra[maxn];

bool solve() {
    int l = 1, r = n, num = 1;
    while (true) {
        if (ra[l] == num) {
            ++num;
            ++l;
        } else if (ra[r] == num) {
            ++num;
            --r;
        } else
            return false;
        if (num == n) return true;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &ra[i]);
    if (solve())
        puts("YES");
    else
        puts("NO");
    return 0;
}