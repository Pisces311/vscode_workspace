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

int T, n, type;
int a;

inline void init() { a = 0; }

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        init();
        up(i, 1, n) {
            cin >> type;
            switch (type) {
                case 1:
                    a += 1;
                    break;
                case 2:
                    a -= 1;
                    break;
            }
        }
        if (a > 0)
            cout << "Kobayashi" << endl;
        else if (a < 0)
            cout << "Tohru" << endl;
        else
            cout << "Draw" << endl;
    }

    return 0;
}