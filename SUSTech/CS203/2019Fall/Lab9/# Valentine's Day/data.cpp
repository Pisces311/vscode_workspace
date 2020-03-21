#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, m;

int random(int a, int b) { return (rand() % (b - a + 1)) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    T = 10;
    cout << T << '\n';
    while (T--) {
        n = random(30, 50), m = random(60, 80);
        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= m; ++i) {
            int u = random(1, n), v = random(1, n);
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}

/*
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*/