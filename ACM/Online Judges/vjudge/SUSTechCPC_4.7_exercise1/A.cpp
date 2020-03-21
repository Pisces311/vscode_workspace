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

int cnt = 0;
string s;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> s) {
        if (s.size() < 4) continue;
        up(i, 0, s.size() - 4) {
            if (s[i] == 'D' || s[i] == 'd')
                if (s[i + 1] == 'O' || s[i + 1] == 'o')
                    if (s[i + 2] == 'G' || s[i + 2] == 'g')
                        if (s[i + 3] == 'E' || s[i + 3] == 'e') ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}