#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, cnt1 = 0, cnt0 = 0, ans = 0;
int sum[maxn], pos[maxn << 1];
char T[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    scanf("%s", T + 1);
    for (int i = 1; i <= N; ++i) {
        if (T[i] == '0') {
            ++cnt0;
            sum[i] = sum[i - 1] - 1;
        } else {
            ++cnt1;
            sum[i] = sum[i - 1] + 1;
        }
    }
    memset(pos, -1, sizeof(pos));
    pos[0 + 100000] = 0;
    for (int i = 1; i <= N; ++i) {
        if (pos[sum[i] + 100000] == -1)
            pos[sum[i] + 100000] = i;
        else
            ans = max(ans, i - pos[sum[i] + 100000]);
    }
    printf("%d %d\n", ans, 2 * min(cnt0, cnt1));

    return 0;
}