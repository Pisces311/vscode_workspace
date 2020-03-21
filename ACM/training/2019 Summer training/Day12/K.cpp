#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int val, id;
    bool operator<(const node& a) const {
        return val == a.val ? id < a.id : val < a.val;
    }
} a[maxn];

int N;
int ans[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + N + 1);
    for (int i = N; i >= 1; --i) ans[a[N - i + 1].id] = i;
    for (int i = 1; i <= N; ++i) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}