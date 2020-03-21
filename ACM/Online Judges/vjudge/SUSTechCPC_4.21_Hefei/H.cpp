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

const int maxn = 1e2 + 5;

int T, N, M, x, dif;
int a[maxn], pre[maxn];

int cal() {
    int mval = INT_MAX, len = 0;
    up(i, 1, N) up(j, 1, i) {
        int x_or = pre[i] ^ pre[j - 1];
        dif = abs(x_or - x);
        if (dif < mval) {
            mval = dif;
            len = i - j + 1;
        } else if (dif == mval)
            len = max(len, i - j + 1);
    }
    return len;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N;
        up(i, 1, N) cin >> a[i];
        up(i, 1, N) pre[i] = pre[i - 1] ^ a[i];
        cin >> M;
        up(i, 1, M) {
            cin >> x;
            cout << cal() << endl;
        }
        cout << endl;
    }

    return 0;
}