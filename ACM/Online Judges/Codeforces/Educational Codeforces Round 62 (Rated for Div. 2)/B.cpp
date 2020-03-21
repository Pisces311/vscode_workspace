#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int t, n, a, b;
string s;
bool a_f, b_f;

inline void init() {
    a = b = 0;
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        cin >> n >> s;
        up(i, 0, n - 1) {
            if (s[i] == '<')
                ++a;
            if (s[i] == '>')
                break;
        }
        dn(i, n - 1, 0) {
            if (s[i] == '>')
                ++b;
            if (s[i] == '<')
                break;
        }
        cout << min(a, b) << endl;
    }

    return 0;
}