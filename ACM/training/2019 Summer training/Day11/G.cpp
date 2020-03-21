#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int AB, AC, BD;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &AB, &AC, &BD)) {
        int son = AB * AC, mon = BD - AC;
        int k = gcd(son, mon);
        printf("%d/%d\n", son / k, mon / k);
    }

    return 0;
}