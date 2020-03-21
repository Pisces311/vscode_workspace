#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1.8e2 + 5;

struct box {
    int x, y, z;
    friend bool operator<(const box& a, const box& b) { return a.x < b.x; }
} a[maxn];

int n, top, cnt = 0;
int dp[maxn];

inline void init() { top = 0; }

int main() {
#ifdef DEBUG
    freopen("D:/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> n && n) {
        cout << "Case " << ++cnt << ": maximum height = ";
        init();
        int in[3];
        up(i, 1, n) {
            cin >> in[0] >> in[1] >> in[2];
            sort(in, in + 3);
            do {
                a[++top] = {in[0], in[1], in[2]};
            } while (next_permutation(in, in + 3));
        }
        sort(a + 1, a + top + 1);
        up(i, 1, top) {
            dp[i] = a[i].z;
            up(j, 1, i - 1) if (a[j].x < a[i].x && a[j].y < a[i].y) dp[i] =
                max(dp[i], dp[j] + a[i].z);
        }
        cout << *max_element(dp + 1, dp + top + 1) << endl;
    }

    return 0;
}