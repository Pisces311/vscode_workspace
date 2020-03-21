#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n, num, cnt_1, cnt_2;
int a[maxn], top = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) {
        cin >> num;
        if (num == 1)
            ++cnt_1;
        else
            ++cnt_2;
    }
    if (cnt_2) a[++top] = 2;
    --cnt_2;
    if (cnt_1) a[++top] = 1;
    --cnt_1;
    up(i, 1, cnt_2) a[++top] = 2;
    up(i, 1, cnt_1) a[++top] = 1;
    up(i, 1, top) cout << a[i] << ' ';
    cout << endl;

    return 0;
}