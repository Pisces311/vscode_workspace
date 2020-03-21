#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
char s[maxn];
vector<int> pos[27];
char name[maxn];
int cnt[27];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    scanf("%s", s + 1);
    up(i, 1, n) {
        int num = s[i] - 'a' + 1;
        pos[num].push_back(i);
    }
    scanf("%d", &m);
    up(i, 1, m) {
        up(i, 1, 26) cnt[i] = 0;
        scanf("%s", name + 1);
        int ma = 0;
        int len = strlen(name + 1);
        up(i, 1, len) {
            int num = name[i] - 'a' + 1;
            ++cnt[num];
            ma = max(ma, pos[num][cnt[num] - 1]);
        }
        printf("%d\n", ma);
    }

    return 0;
}