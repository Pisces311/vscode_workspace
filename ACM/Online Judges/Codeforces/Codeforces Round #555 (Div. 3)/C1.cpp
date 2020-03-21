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

const int maxn = 2e6 + 5;

int n, cnt = 0;
int a[maxn];
int order[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    int l = 1, r = n, cur = 0;
    while (cnt <= n) {
        if (a[l] < a[r]) {
            if (cur < a[l]) {
                cur = a[l];
                ++l;
                order[++cnt] = 1;
            } else if (cur < a[r]) {
                cur = a[r];
                --r;
                order[++cnt] = 2;
            } else
                break;
        } else {
            if (cur < a[r]) {
                cur = a[r];
                --r;
                order[++cnt] = 2;
            } else if (cur < a[l]) {
                cur = a[l];
                ++l;
                order[++cnt] = 1;
            } else
                break;
        }
    }
    cout << cnt << endl;
    up(i, 1, cnt) {
        if (order[i] == 1)
            cout << 'L';
        else
            cout << 'R';
    }
    cout << endl;

    return 0;
}