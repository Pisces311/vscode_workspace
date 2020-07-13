#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int h1, h2, m1, m2, s1, s2;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    int ans = h1 * 3600 + m1 * 60 + s1 - h2 * 3600 - m2 * 60 - s2;
    printf("%d\n", abs(ans));

    return 0;
}