#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int n, sum = 0;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(i, 2, n) {
        if (a[i] == 1) {
            if (a[i - 1] == 2)
                sum += 3;
            else
                sum += 4;
        } else if (a[i] == 2) {
            if (a[i - 1] == 1) {
                sum += 3;
                if (a[i - 2] == 3) --sum;
            } else {
                sum = -1;
                break;
            }
        } else {
            if (a[i - 1] == 1)
                sum += 4;
            else {
                sum = -1;
                break;
            }
        }
    }
    if (sum == -1)
        cout << "Infinite" << endl;
    else {
        cout << "Finite" << endl << sum << endl;
    }

    return 0;
}