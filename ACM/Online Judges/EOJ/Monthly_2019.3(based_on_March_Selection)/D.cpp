#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int n, m;
int x_1, y_1, x_2, y_2;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    int dif = abs(x_1 - x_2) + abs(y_1 - y_2) - 2;
    if (dif & 1) {
        cout << "Lose" << endl;
    } else
        cout << "Win" << endl;

    return 0;
}