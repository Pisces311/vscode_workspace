#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

int n;
int a[maxn];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n) {
        scanf("%d", &a[i]);
        pq.push(a[i]);
    }
    int cnt = 0, day = 1;
    while (!pq.empty()) {
        if (day <= pq.top()) {
            ++cnt;
            ++day;
        }
        pq.pop();
    }
    printf("%d\n", cnt);

    return 0;
}