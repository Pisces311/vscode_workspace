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

int n;
int cnt = 1;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    if (n < 10) {
        cout << 9 << endl;
        return 0;
    }
    while (true) {
        n += 1;
        while (n / 10.0 == (int)(n / 10)) n /= 10;
        if (n < 10) {
            cnt += 9;
            break;
        } else
            ++cnt;
    }
    cout << cnt << endl;

    return 0;
}