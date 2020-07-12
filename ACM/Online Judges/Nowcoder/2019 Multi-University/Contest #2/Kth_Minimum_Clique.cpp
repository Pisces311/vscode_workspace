#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

struct clique {
    int st;
    long long w;
    bitset<105> sta;
    bool operator<(const clique& a) const { return w > a.w; }
} a, v;

int n, k;
int w[maxn];
char g[maxn][maxn];
bitset<105> s[maxn];
priority_queue<clique> pq;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= n; j++)
            if (g[i][j] == '1') s[i].set(j);
    }
    a.w = 0, a.st = 1;
    a.sta.set();
    pq.push(a);
    while (!pq.empty()) {
        clique x = pq.top();
        pq.pop();
        k--;
        if (!k) return !printf("%lld\n", x.w);
        for (int i = x.st; i <= n; i++) {
            if (!x.sta.test(i)) continue;
            v.sta = x.sta & s[i];
            v.w = x.w + w[i], v.st = i + 1;
            pq.push(v);
        }
    }
    puts("-1");

    return 0;
}