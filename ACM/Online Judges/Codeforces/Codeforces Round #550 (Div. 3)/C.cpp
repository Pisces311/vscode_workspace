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

int n;
int a[maxn], inc[maxn], decl[maxn], cnt[maxn];
bool vis[maxn];
int t1 = 0, t2 = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(n);
    up(i, 1, n) scan(a[i]);
    up(i, 1, n) {
        ++cnt[a[i]];
        if (cnt[a[i]] >= 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    if (n == 1) {
        cout << 1 << endl << a[1] << endl << 0 << endl << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    inc[++t1] = a[1];
    decl[++t2] = a[2];
    up(i, 3, n) {
        if (a[i] > inc[t1]) {
            inc[++t1] = a[i];
            vis[i] = true;
        }
    }
    up(i, 3, n) {
        if (a[i] > decl[t2] && !vis[i]) {
            decl[++t2] = a[i];
        }
    }
    cout << t1 << endl;
    up(i, 1, t1) cout << inc[i] << ' ';
    cout << endl << t2 << endl;
    dn(i, t2, 1) cout << decl[i] << ' ';
    cout << endl;

    return 0;
}