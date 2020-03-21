#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1 + 5;

int T, vote;
int v[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        mem(v, 0);
        up(i, 1, 5) {
            cin >> vote;
            ++v[vote];
        }
        int p = 0, pos;
        up(i, 1, 5) {
            if (p < v[i]) {
                p = v[i];
                pos = i;
            }
        }
        cout << pos << endl;
    }

    return 0;
}