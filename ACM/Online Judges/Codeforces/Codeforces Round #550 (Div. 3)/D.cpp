#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n, ma = 0, pos, val;
int a[maxn], cnt[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    up(i, 0, maxn) {
        if (ma < cnt[i]) {
            ma = cnt[i];
            val = i;
        }
    }
    up(i, 1, n) {
        if (a[i] == val) {
            pos = i;
            break;
        }
    }
    cout << n - ma << endl;
    up(i, pos + 1, n) {
        if (a[i] > val) {
            cout << 2 << ' ';
            cout << i << ' ' << i - 1 << endl;
        } else if (a[i] < val) {
            cout << 1 << ' ';
            cout << i << ' ' << i - 1 << endl;
        }
    }
    dn(i, pos - 1, 1) {
        if (a[i] > val) {
            cout << 2 << ' ';
            cout << i << ' ' << i + 1 << endl;
        } else if (a[i] < val) {
            cout << 1 << ' ';
            cout << i << ' ' << i + 1 << endl;
        }
    }

    return 0;
}