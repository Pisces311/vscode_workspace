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

int x;
int bit[30];
int ans[30], top_ans = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> x;
    int top = 0;
    while (x) {
        bit[++top] = x % 2;
        x /= 2;
    }
    if (accumulate(bit + 1, bit + top + 1, 0) == top) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1;
    while (top != 0) {
        if (cnt & 1) {
            dn(i, top, 1) {
                if (bit[i] != 1) break;
                --top;
            }
            ans[++top_ans] = top;
            dn(i, top, 1) {
                if (bit[i] == 1)
                    bit[i] = 0;
                else
                    bit[i] = 1;
            }
            if (accumulate(bit + 1, bit + top + 1, 0) == top) break;
        } else {
            up(i, 1, top) {
                if (bit[i] == 0) {
                    bit[i] = 1;
                    break;
                } else
                    bit[i] = 0;
            }
            if (accumulate(bit + 1, bit + top + 1, 0) == top) break;
        }
        ++cnt;
    }
    cout << cnt << endl;
    up(i, 1, top_ans) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}