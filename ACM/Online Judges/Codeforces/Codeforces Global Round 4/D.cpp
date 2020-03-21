#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int n;
bool isprime[2000], vis[maxn];

void pre() {
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i < 2000; ++i) {
        if (isprime[i]) {
            for (int j = i + i; j < 2000; j += i) isprime[j] = false;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    pre();
    int p;
    for (int i = n; i < 2000; ++i) {
        if (isprime[i]) {
            p = i;
            break;
        }
    }
    printf("%d\n", p);
    for (int i = 1; i <= n; ++i) {
        if (i != n)
            printf("%d %d\n", i, i + 1);
        else
            printf("%d %d\n", i, 1);
    }
    p -= n;
    if (!p) return 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || vis[i + 2]) continue;
        printf("%d %d\n", i, i + 2);
        vis[i] = true;
        vis[i + 2] = true;
        --p;
        if (!p) break;
    }

    return 0;
}