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

const int maxn = 17;

int n;
int a[maxn];
bool ok;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    int tmp = n;
    while (tmp) {
        if (tmp == 1) {
            cout << 1 << endl;
            return 0;
        }
        int l = 1, r = tmp;
        while (l < n) {
            ok = true;
            up(i, l + 1, r) {
                if (a[i] < a[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << tmp << endl;
                return 0;
            }
            int temp = r;
            r = r + 1 + (r - l);
            l = temp + 1;
        }
        tmp /= 2;
    }

    return 0;
}