#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n, k;
int ski[maxn], bel[maxn];
int get_pos[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> k;
    up(i, 1, n) {
        cin >> ski[i];
        get_pos[ski[i]] = i;
    }
    int flag = 1;
    dn(i, n, 1) {
        int l = k, r = k;
        int pos = get_pos[i];
        if (bel[pos]) continue;
        bel[pos] = flag;
        int tmp = pos - 1;
        while (l--) {
            if (tmp < 1) break;
            while (bel[tmp]) {
                tmp -= 2 * k + 1;
                if (tmp < 1) break;
            }
            if (tmp < 1) break;
            bel[tmp] = flag;
            tmp--;
        }
        tmp = pos + 1;
        while (r--) {
            if (tmp > n) break;
            while (bel[tmp]) {
                tmp += 2 * k + 1;
                if (tmp > n) break;
            }
            if (tmp > n) break;
            bel[tmp] = flag;
            tmp++;
        }
        flag = (flag == 1) ? 2 : 1;
    }
    up(i, 1, n) cout << bel[i];
    cout << endl;

    return 0;
}