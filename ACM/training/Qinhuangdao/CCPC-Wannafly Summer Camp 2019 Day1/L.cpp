#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 5;

int n;
int love[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &love[i]);
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (love[love[love[i]]] == i) {
            ok = false;
            break;
        }
    }
    printf(!ok ? "YES\n" : "NO\n");

    return 0;
}