#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 5e5 + 5;

struct node {
    ll x, y;
    double operator-(const node& a) const {
        return sqrt(1.0 * pow(a.x - x, 2) + pow(a.y - y, 2));
    }
    ll cross(const node& a, const node& b) {
        return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
    }
} g[maxn], stk[maxn];

int N, pos, top;

inline void get_left_down() {
    int left = INT_MAX, down = INT_MAX;
    up(i, 1, N) if (down > g[i].y || (down == g[i].y && left > g[i].x)) {
        left = g[i].x;
        down = g[i].y;
        pos = i;
    }
    swap(g[1], g[pos]);
}

bool cmp(node n1, node n2) {
    ll prod = g[1].cross(n1, n2);
    if (prod > 0 || (prod == 0 && g[1] - n1 < g[1] - n2)) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    up(i, 1, N) scanf("%lld %lld", &g[i].x, &g[i].y);
    get_left_down();
    sort(g + 2, g + N + 1, cmp);
    stk[0] = g[1];
    stk[1] = g[2];
    top = 1;
    up(i, 3, N) {
        while (top && stk[top - 1].cross(stk[top], g[i]) < 0) --top;
        stk[++top] = g[i];
    }
    printf("%d\n", top + 1);

    return 0;
}