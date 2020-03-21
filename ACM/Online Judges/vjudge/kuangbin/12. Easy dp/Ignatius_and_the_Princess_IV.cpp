#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxN = 1e6 + 5;

int N, ans, pos;
int cnt[maxN];

inline void init() {
    memset(cnt, 0, sizeof(cnt));
    pos = ans = 0;
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> N) {
        init();
        int tmp;
        up(i, 1, N) {
            cin >> tmp;
            ++cnt[tmp];
            if (cnt[tmp] > ans) {
                ans = cnt[tmp];
                pos = tmp;
            }
        }
        cout << pos << endl;
    }

    return 0;
}