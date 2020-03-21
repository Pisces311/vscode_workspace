#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a;
int b[10];

inline bool cal(int a[], int top) {
    int sum = 0;
    up(i, 0, top) sum += a[i];
    if (sum % 4 == 0)
        return true;
    else
        return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &a);
    while (true) {
        int top = 0, tmp = a;
        while (tmp != 0) {
            b[top++] = tmp % 10;
            tmp /= 10;
        }
        if (!cal(b, top))
            a += 1;
        else
            break;
    }
    printf("%d\n", a);

    return 0;
}