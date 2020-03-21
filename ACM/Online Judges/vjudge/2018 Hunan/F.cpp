#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

struct node {
    int in;
    ll x, y, z;
    bool operator<(const node& a) const {
        ll tmp1 = z * (a.x + a.y), tmp2 = a.z * (x + y);
        if (tmp1 == tmp2) return in < a.in;
        return tmp1 > tmp2;
    }
} a[maxn];

int n;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        up(i, 1, n) {
            scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].z);
            a[i].in = i;
        }
        sort(a + 1, a + n + 1);
        up(i, 1, n) {
            printf("%d", a[i].in);
            if (i != n) printf(" ");
        }
        printf("\n");
    }

    return 0;
}