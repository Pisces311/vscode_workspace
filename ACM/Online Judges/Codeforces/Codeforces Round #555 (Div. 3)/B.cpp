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
string a;
int f[10];
bool start = false;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> a;
    up(i, 1, 9) cin >> f[i];
    int len = a.size();
    up(i, 0, len - 1) {
        if (f[a[i] - '0'] > a[i] - '0') {
            a[i] = f[a[i] - '0'] + '0';
            start = true;
        } else if (f[a[i] - '0'] < a[i] - '0' && start)
            break;
    }
    cout << a << endl;

    return 0;
}