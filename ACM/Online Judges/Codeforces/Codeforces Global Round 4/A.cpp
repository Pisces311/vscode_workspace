#include <bits/stdc++.h>
using namespace std;

struct node {
    int w, id;
    bool operator<(const node& a) const { return w < a.w; }
} a[105];

int n, sum = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].w);
        a[i].id = i;
        sum += a[i].w;
    }
    int half = sum / 2 + 1;
    sort(a + 2, a + n + 1);
    int now = a[1].w, pos = n;
    for (int i = 2; i <= n; ++i) {
        if (now < half)
            now += a[i].w;
        else {
            pos = i - 1;
            break;
        }
    }
    bool ok = true;
    for (int i = 2; i <= pos; ++i) {
        if (a[1].w < 2 * a[i].w) {
            ok = false;
        }
    }
    if (ok) {
        printf("%d\n", pos);
        for (int i = 1; i <= pos; ++i) printf("%d ", a[i].id);
        printf("\n");
    } else
        printf("0\n");

    return 0;
}