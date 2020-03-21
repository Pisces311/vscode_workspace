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
        } else if (a[l] > a[r]) {
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
        } else
            break;
    }
    if (a[l] == a[r]) {
        int tmp1 = cur, tmp2 = cur;
        int num1 = 0, num2 = 0;
        up(i, l, r) {
            if (tmp1 < a[i]) {
                tmp1 = a[i];
                ++num1;
            } else
                break;
        }
        dn(i, r, l) {
            if (tmp2 < a[i]) {
                tmp2 = a[i];
                ++num2;
            } else
                break;
        }
        if (num1 >= num2)
            while (num1--) order[++cnt] = 1;
        else
            while (num2--) order[++cnt] = 2;
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